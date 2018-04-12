cmake_minimum_required(VERSION 3.8)
project(Allocator_Switcher)

set(CMAKE_CXX_STANDARD 11)
include_directories(src)
set(SOURCE_FILES
        src/DefaultAllocator.hpp
        src/Global-Switcher.hpp
        src/GlobalManager.hpp
        src/MemoryManager.hpp
        test/SwitcherTester.cpp src/DefaultAllocator.cpp src/GlobalManager.cpp src/CMemoryManagerSwitcher.cpp src/CMemoryManagerSwitcher.hpp src/CAllocatedOn.cpp src/CAllocatedOn.hpp src/CRuntimeHeapStrategy.cpp src/CRuntimeHeapStrategy.hpp src/CCurrentMemoryManagerStrategy.cpp src/CCurrentMemoryManagerStrategy.hpp)

add_executable(Allocator_Switcher ${SOURCE_FILES})