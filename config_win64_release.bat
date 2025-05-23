@echo off
SETLOCAL EnableDelayedExpansion

call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

PowerShell -Command "& {Get-ChildItem build/* -Exclude Debug,Release | Remove-Item -Recurse -Force -ErrorAction SilentlyContinue}"

conan install . --build=missing --profile=Profiles/WinRel
cmake --preset conan-release
cmake --build build --target install --preset conan-release

ENDLOCAL
