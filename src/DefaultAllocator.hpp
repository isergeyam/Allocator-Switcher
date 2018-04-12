#ifndef ALLOCATOR_SWITCHER_DEFAULTALLOCATOR_HPP
#define ALLOCATOR_SWITCHER_DEFAULTALLOCATOR_HPP
#include "MemoryManager.hpp"
class CDefaultAllocator : public IMemoryManager {
  void *Alloc(std::size_t __n) override ;
  void Free(void *ptr) override;
};
#endif
