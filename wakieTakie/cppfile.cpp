// wakie talkie
#include <iostream>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <mutex>
#include <vector>
#include <openssl/aes.h>
#include <signal.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

const size_t AES_BLOCK_SIZE = 16;

std::mutex logMutex;
std::vector<std::string> onlineUsers;

// Simple Caesar cipher for basic encryption
std::string encrypt(const std::string& message, const std::string& key) {
	AES_KEY aesKey;
	AES_set_encrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), 128, &aesKey);

	size_t messageLength = message.length();
	unsigned char* encryptedData = new unsigned char[messageLength + AES_BLOCK_SIZE];
	memset(encryptedData, 0, messageLength + AES_BLOCK_SIZE);

	AES_encrypt(reinterpret_cast<const unsigned char*>(message.c_str()), encryptedData, &aesKey);

	std::string encryptedMessage(reinterpret_cast<char*>(encryptedData), messageLength + AES_BLOCK_SIZE);
	delete[] encryptedData;

	return encryptedMessage;
}

std::string decrypt(const std::string& encryptedMessage, const std::string& key) {
	AES_KEY aesKey;
	AES_set_decrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), 128, &aesKey);

	size_t encryptedLength = encryptedMessage.length();
	unsigned char* decryptedData = new unsigned char[encryptedLength];
	memset(decryptedData, 0, encryptedLength);

	AES_decrypt(reinterpret_cast<const unsigned char*>(encryptedMessage.c_str()), decryptedData, &aesKey);

	std::string decryptedMessage(reinterpret_cast<char*>(decryptedData), encryptedLength);
	delete[] decryptedData;

	return decryptedMessage;
}

void logError(const std::string& errorMessage) {
	std::lock_guard<std::mutex> lock(logMutex);
	std::ofstream logFile("error_log.txt", std::ios::app);
	if (logFile.is_open()) {
		logFile << "[" << std::time(0) << "] " << errorMessage << std::endl;
		logFile.close();
	} else {
		std::cerr << "Error: Unable to open log file." << std::endl;
	}
}

void handle_signal(int signal) {
	std::cout << "Received signal: " << signal << ". Exiting Walkie-Talkie." << std::endl;
	exit(signal);
}

void printOnlineUsers() {
	std::cout << "Online Users: ";
	for (const auto& user : onlineUsers) {
		std::cout << user << " ";
	}
	std::cout << std::endl;
}

void receive_messages(int sock, const std::string& nickname, const std::string& key) {
	char buffer[1024];
	sockaddr_in addr{};
	socklen_t addr_len = sizeof(addr);

	signal(SIGINT, handle_signal);

	while (true) {
		ssize_t bytes_received = recvfrom(sock, buffer, sizeof(buffer), 0, reinterpret_cast<sockaddr*>(&addr), &addr_len);
		if (bytes_received == -1) {
			perror("recvfrom");
			logError("Error receiving message");
			break;
		}
		buffer[bytes_received] = '\0';

		// Decrypt received message
		std::string decrypted_message = decrypt(buffer, key);

		std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		std::cout << "[" << std::ctime(&now) << "] " << nickname << " received from "
		          << inet_ntoa(addr.sin_addr) << ": " << decrypted_message << std::endl;

		// Extract username from the decrypted message
		std::string sender = decrypted_message.substr(decrypted_message.find(":") + 2, decrypted_message.find(" ") - 2);

		// Add the user to the online list if not already present
		auto it = std::find(onlineUsers.begin(), onlineUsers.end(), sender);
		if (it == onlineUsers.end()) {
			onlineUsers.push_back(sender);
		}
	}
}

void send_messages(int sock, const sockaddr_in& server_address, const std::string& nickname, const std::string& key) {
	while (true) {
		std::string message;
		std::cout << "Type your message (type 'exit' to quit, 'list' to see commands): ";
		std::getline(std::cin, message);

		if (message == "exit") {
			std::cout << "Exiting Walkie-Talkie." << std::endl;
			sendto(sock, "exit", 4, 0, reinterpret_cast<const sockaddr*>(&server_address), sizeof(server_address));
			break;
		} else if (message == "list") {
			std::cout << "Commands: 'exit', 'list', 'status', 'users'" << std::endl;
			continue;
		} else if (message == "status") {
			std::cout << "Status: Online" << std::endl;
			continue;
		} else if (message == "users") {
			printOnlineUsers();
			continue;
		}

		// Encrypt the message before sending
		std::string encrypted_message = encrypt(message, key);

		std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		std::string formatted_message = "[" + std::ctime(&now) + "] " + nickname + ": " + encrypted_message;
		sendto(sock, formatted_message.const char [2], char* formatted_message.length(), 0,
		       reinterpret_cast<const sockaddr*>(&server_address), sizeof(server_address));
	}
}

int main() {
	// Set up the socket
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock == -1) {
		perror("socket");
		logError("Error creating socket");
		return 1;
	}

	// Set up server address
	sockaddr_in server_address{};
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;

	std::string server_ip;
	std::cout << "Enter the server IP address (e.g., 127.0.0.1): ";
	std::getline(std::cin, server_ip);
	server_address.sin_addr.s_addr = inet_addr(server_ip.c_str());

	server_address.sin_port = htons(0); // Use dynamic port assignment

	// Bind the socket
	if (bind(sock, reinterpret_cast<const sockaddr*>(&server_address), sizeof(server_address)) == -1) {
		perror("bind");
		logError("Error binding socket");
		close(sock);
		return 1;
	}

	// Get user nickname
	std::string nickname;
	std::cout << "Enter your nickname: ";
	std::getline(std::cin, nickname);

	// Get user password
	std::string password;
	std::cout << "Enter your password: ";
	std::getline(std::cin, password);

	// Hash the password (this is a simple example; in a real-world scenario, use a secure hashing algorithm)
	std::hash<std::string> hasher;
	std::string hashed_password = std::to_string(hasher(password));

	std::cout << "Walkie-Talkie started. Your nickname is " << nickname << "." << std::endl;

	// Create two threads for sending and receiving messages
	std::thread receive_thread(receive_messages, sock, nickname, hashed_password);
	std::thread send_thread(send_messages, sock, server_address, nickname, hashed_password);

	// Wait for threads to finish
	receive_thread.join();
	send_thread.join();

	// Close the socket
	close(sock);

	return 0;
}


