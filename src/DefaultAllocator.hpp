#include "MemoryManager.hpp"
namespace __sg_lib {
class CDefaultAllocator : public IMemoryManager {
  virtual void *Alloc(std::size_t __n);
  virtual void Free(void *ptr);
};
} //__sg_lib
