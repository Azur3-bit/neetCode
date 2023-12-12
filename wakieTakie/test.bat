@echo off
echo Enter the server IP address (e.g., 127.0.0.1): 127.0.0.1
echo Enter your nickname: Sunil
echo Enter your password: secret
echo.
echo ------------------------------------------------
echo.
echo Walkie-Talkie started. Your nickname is Sunil.
echo.
echo ------------------------------------------------
echo.

echo Type your message (type 'exit' to quit, 'list' to see commands):
echo.
echo ------------------------------------------------
echo.

echo [Mon Nov 13 12:34:56 2023] Alice received from 127.0.0.1: Hello, how are you? 
echo [Mon Nov 13 12:35:02 2023] Alice sent to 127.0.0.1: I'm doing well, thanks!
echo.
echo ------------------------------------------------
echo.

echo Type your message (type 'exit' to quit, 'list' to see commands): list
echo Commands: 'exit', 'list', 'status', 'users'

echo Type your message (type 'exit' to quit, 'list' to see commands): status 
echo Status: Online

echo Type your message (type 'exit' to quit, 'list' to see commands): users
echo Online Users: Alice Bob

echo Type your message (type 'exit' to quit, 'list' to see commands): exit
echo Exiting Walkie-Talkie.

echo.
echo ------------------------------------------------
echo.

echo EXITED  Successfully !!