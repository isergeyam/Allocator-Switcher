cmake_minimum_required(VERSION 3.8)
project(Allocator_Switcher)

set(CMAKE_CXX_STANDARD 14)
include_directories(src)
add_subdirectory(../xor-list/ ${CMAKE_CURRENT_BINARY_DIR}/xorlist)
include_directories(../xor-list)
set(SOURCE_FILES
        src/DefaultAllocator.hpp
        src/Global-Switcher.hpp
        src/GlobalManager.hpp
        src/MemoryManager.hpp
        test/SwitcherTester.cpp src/DefaultAllocator.cpp src/GlobalManager.cpp src/CMemoryManagerSwitcher.cpp src/CMemoryManagerSwitcher.hpp src/CAllocatedOn.cpp src/CAllocatedOn.hpp src/CRuntimeHeapStrategy.cpp src/CRuntimeHeapStrategy.hpp src/CCurrentMemoryManagerStrategy.cpp src/CCurrentMemoryManagerStrategy.hpp src/CStackAllocatorWrapper.cpp src/CStackAllocatorWrapper.hpp)

add_executable(Allocator_Switcher ${SOURCE_FILES})