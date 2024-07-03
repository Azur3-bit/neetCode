@echo off

REM Prompt for C++ file name (with .cpp extension)
set /p cpp_file="Enter the C++ file name (with .cpp extension): "

REM Extract the file name without extension
for %%F in ("%cpp_file%") do set cpp_name=%%~nF

REM Compile the C++ file using g++
g++ %cpp_file% -o %cpp_name%.exe

REM Check if the compilation was successful
if errorlevel 1 (
    echo Compilation failed!
    exit /b
)

REM Run the compiled program
%cpp_name%.exe

REM Compare output.txt and ExpectedOutput.txt and store the result in "result.txt"
FC output.txt ExpectedOutput.txt > result.txt

REM Store the errorlevel value (0 if no differences encountered, 1 otherwise)
set "result=%errorlevel%"

REM Cleanup - delete the compiled executable with .exe extension
del %cpp_name%.exe

echo.

REM Check the result and print "Good code" if no differences were encountered
if %result% equ 0 (
	echo **** *** *** *** *** *** *** *** *** *** *** *** *** *** ****.
    echo.
	echo FC: no differences encountered 
	echo.
	echo No Differnce FOUND between ExpectedOutput.txt and output.txt
	echo.
	echo **** *** *** *** *** *** *** *** *** *** *** *** *** *** ****.
	
) else (
    echo Differences found in the output:
    type result.txt
)

echo.
REM pause
