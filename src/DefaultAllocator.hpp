#include "MemoryManager.hpp"
class CDefaultAllocator : public IMemoryManager {
  void *Alloc(std::size_t __n) override ;
  void Free(void *ptr) override;
};
