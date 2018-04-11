cmake_minimum_required(VERSION 3.8)
project(Allocator_Switcher)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/DefaultAllocator.hpp
        src/Global-Switcher.cpp
        src/GlobalManager.hpp
        src/MemoryManager.hpp
        test/SwitcherTester.cpp src/DefaultAllocator.cpp src/GlobalManager.cpp)

add_executable(Allocator_Switcher ${SOURCE_FILES})