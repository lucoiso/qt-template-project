@echo off
SETLOCAL EnableDelayedExpansion

call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"

PowerShell -Command "& {Get-ChildItem build/* -Exclude Debug,Release | Remove-Item -Recurse -Force -ErrorAction SilentlyContinue}"

conan install . --build=missing --profile=Profiles/WinDbg
cmake --preset conan-debug
cmake --build build --target install --preset conan-debug

ENDLOCAL
