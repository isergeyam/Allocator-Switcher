cmake_minimum_required(VERSION 3.5)
project(Allocator_Switcher)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
include_directories(src)
set(SOURCE_FILES
        src/MemoryManager.hpp
        src/DefaultAllocator.hpp
        src/GlobalManager.hpp
        Stack-Allocator/src/StackAllocator.hpp
        Stack-Allocator/src/XorList.hpp
        src/CMemoryManagerSwitcher.hpp
        src/CAllocatedOn.hpp
        src/CRuntimeHeapStrategy.hpp
        src/CCurrentMemoryManagerStrategy.hpp
        src/CAllocatorWrapper.hpp
        src/Global-Switcher.hpp src/CAllocatorDebugWrapper.hpp src/CMAllocator.hpp src/TestLib.hpp)
add_subdirectory(Stack-Allocator)
add_executable(AllocatorTest ${SOURCES_FILE} test/TestAllocator.cpp)
add_executable(GeneralTest ${SOURCES_FILE} test/GeneralTest.cpp)
add_executable(TestOverload ${SOURCES_FILE} test/TestOverload.cpp)
target_link_libraries(GeneralTest gtest)
if (UNIX)
    target_link_libraries(GeneralTest pthread)
endif()
