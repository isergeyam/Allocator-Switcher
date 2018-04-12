cmake_minimum_required(VERSION 3.5)
project(Allocator_Switcher)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE  "-O3")
include_directories(src)
set(SOURCE_FILES
        src/DefaultAllocator.hpp
        src/Global-Switcher.hpp
        src/GlobalManager.hpp
        src/MemoryManager.hpp
        src/StackAllocator.hpp
        src/XorList.hpp
        src/DefaultAllocator.cpp src/GlobalManager.cpp src/CMemoryManagerSwitcher.cpp src/CMemoryManagerSwitcher.hpp src/CAllocatedOn.hpp src/CRuntimeHeapStrategy.cpp src/CRuntimeHeapStrategy.hpp src/CCurrentMemoryManagerStrategy.cpp src/CCurrentMemoryManagerStrategy.hpp src/CStackAllocatorWrapper.cpp src/CStackAllocatorWrapper.hpp)
add_executable(Allocator_Switcher test/SwitcherTester.cpp ${SOURCE_FILES})
add_executable(XorListTest test/XorListTest.cpp ${SOURCES_FILE})
add_executable(AllocatorTest test/TestAllocator.cpp ${SOURCES_FILE})