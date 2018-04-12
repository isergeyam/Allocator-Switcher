#include "MemoryManager.hpp"
namespace __sg_lib {
class CDefaultAllocator : public IMemoryManager {
  void *Alloc(std::size_t __n) override ;
  void Free(void *ptr) override;
};
} //__sg_lib
