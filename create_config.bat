@echo off
setlocal

:: Yeu cau nhap ten folder
set /p folderName=Nhap ten folder: 
set /p mainFile=Nhap ten file chinh (vi du: main.cpp): 
set /p cppFile=Nhap ten file phu (vi du: file.cpp): 

:: Tao thu muc .vscode neu chua ton tai
if not exist ".vscode" (
    mkdir .vscode
)

:: Tao file tasks.json
(
echo {
echo   "version": "2.0.0",
echo   "tasks": [
echo     {
echo       "label": "build %folderName%",
echo       "type": "cppbuild",
echo       "command": "C:\\mingw64\\bin\\g++.exe",
echo       "args": [
echo         "-g",
echo         "${workspaceFolder}/%folderName%/%mainFile%",
echo         "${workspaceFolder}/%folderName%/%cppFile%",
echo         "-o",
echo         "${workspaceFolder}/%folderName%/%folderName%Program.exe"
echo       ],
echo       "options": {
echo         "cwd": "${workspaceFolder}/%folderName%"
echo       },
echo       "problemMatcher": ["$gcc"],
echo       "group": {
echo         "kind": "build",
echo         "isDefault": true
echo       },
echo       "detail": "Task to build %folderName% program"
echo     }
echo   ]
echo }
) > ".vscode\tasks.json"

:: Tao file launch.json
(
echo {
echo   "version": "0.2.0",
echo   "configurations": [
echo     {
echo       "name": "Debug %folderName%Program",
echo       "type": "cppdbg",
echo       "request": "launch",
echo       "program": "${workspaceFolder}/%folderName%/%folderName%Program.exe",
echo       "args": [],
echo       "stopAtEntry": false,
echo       "cwd": "${workspaceFolder}/%folderName%",
echo       "environment": [],
echo       "externalConsole": false,
echo       "MIMode": "gdb",
echo       "miDebuggerPath": "C:\\mingw64\\bin\\gdb.exe",
echo       "setupCommands": [
echo         {
echo           "description": "Enable pretty-printing for gdb",
echo           "text": "-enable-pretty-printing",
echo           "ignoreFailures": true
echo         }
echo       ],
echo       "preLaunchTask": "build %folderName%",
echo       "internalConsoleOptions": "openOnSessionStart"
echo     }
echo   ]
echo }
) > ".vscode\launch.json"

echo Da tao thanh cong cac file tasks.json va launch.json trong thu muc .vscode.

endlocal
