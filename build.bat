
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=D:/C++Dinge/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_PREFIX_PATH=D:\C++Dinge\vcpkg\vcpkg\installed\x64-windows
cmake --build . --config Release

