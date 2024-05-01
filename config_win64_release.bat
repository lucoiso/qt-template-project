@call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
conan install . --build=missing --profile=Profiles/WinRel
cmake --preset conan-release
cmake --build build --target install --preset conan-release