@echo off

cls
echo compiling
g++ %1 -o %1.exe -DDEBUG

echo finish
if %ERRORLEVEL% EQU 0 (
	%1.exe
)