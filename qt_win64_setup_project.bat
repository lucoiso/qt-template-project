conan install . --build=missing --profile=Profiles/WinRel
cmake --preset conan-release
cmake --build build --target install --preset conan-release
conan install . --build=missing --profile=Profiles/WinDbg
cmake --preset conan-debug
cmake --build build --target install --preset conan-debug