// Practicing Maps

#include <iostream>
using namespace std;

// additional_libraries
#include <vector>
#include <array>
#include <unordered_map>
#include <map>
#include <set>

// Classes

// Functions for Traversal of map

void Traversal(unordered_map<string, int> tmp)
{
	cout << "Name"
		 << "\t"
		 << "Marks"
		 << "\n";
	// unordered_map<string,int> :: iterator it;

	for (auto it : tmp)
	{
		cout << it.first << "\t" << it.second << "\n";
	}
}

// funtion

// Map Input function
unordered_map<string, int> AddingElementsToMap(unordered_map<string, int> &tmp)
{

	string i1;
	int i2;

	cout << "Enter Number of Entries : "
		 << "\n";
	int n;
	cin >> n;
	// n++;
	while (n--)
	{
		cout << "Enter First Value "
			 << "\n";
		cin >> i1;
		cout << "Enter Second Value "
			 << "\n";
		cin >> i2;

		tmp.insert(pair<string, int>(i1, i2));
	}
	return tmp;
}

void PrintingArray(int temp[], int size)
{

	// int size = *(&temp + 1) - temp;
	cout << "Inside Printing Array Funtion : "
		 << "\n";
	cout << "SIZE : " << size << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << temp[i] << "\n";
	}
}

int main()
{
	// Main Code Function

	// Creating a map

	// unordered_map<string, int> S;

	// AddingElementsToMap(S);
	// Traversal(S);

	// find the modulus of a number by the size of the string
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = sizeof(array) / sizeof(array[0]);
	// cout << "Size of the Array is : " << size << "\n";
	cout << "Item"
		 << "\t"
		 << "Hashcode"
		 << "\n";

	// PrintingArray(array, size);

	// Finding Hashcode For Every Element
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << "\t" << array[i] % 5 << "\n";
	}
	return 0;
}