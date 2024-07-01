## VSCode gtest HowTo
## clone this repo as you need, then perform following commands
mkdir build
cmake -S . -B build
cmake --build build
## After tests are built just do:
cd build
ctest