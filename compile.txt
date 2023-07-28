@echo off

REM Prompt for C++ file name
set /p cpp_file="Enter the C++ file name (without extension): "
set cpp_file=%cpp_file%.cpp

REM Compile the C++ file using g++
g++ %cpp_file% -o a.exe

REM Check if the compilation was successful
if errorlevel 1 (
    echo Compilation failed!
    exit /b
)

REM Run the compiled program
a.exe

REM Compare output.txt and ExpectedOutput.txt
FC output.txt ExpectedOutput.txt

REM Cleanup - delete the compiled executable
del a.exe

echo Finished!
pause
