//
// Created by sg on 11.04.18.
//
#include "DefaultAllocator.hpp"
namespace __sg_lib {
void *CDefaultAllocator::Alloc(std::size_t __n) { return std::malloc(__n); }
void CDefaultAllocator::Free(void *ptr) { free(ptr); }
}

