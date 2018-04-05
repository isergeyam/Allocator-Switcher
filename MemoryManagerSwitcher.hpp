#include "MemoryManager.hpp"
#include <new>
namespace __sg_lib {
class DefaultAllocator : public IMemoryManager {
  virtual void *Alloc(std::size_t __n) { return std::malloc(__n); }
  virtual void Free(void *ptr) { free(ptr); }
};
class CMemoryManagerSwitcher {
private:
  static IMemoryManager *current_manager;

public:
  CMemoryManagerSwitcher() = delete;
  ~CMemoryManagerSwitcher() = delete;
  CMemoryManagerSwitcher(const CMemoryManagerSwitcher &) = delete;
  CMemoryManagerSwitcher &operator=(const CMemoryManagerSwitcher &) = delete;
  static IMemoryManager *GetCurrentAllocator() { return current_manager; }
  static void SetAllocator(IMemoryManager *new_manager) {
    current_manager = new_manager;
  }
};
IMemoryManager *CMemoryManagerSwitcher::current_manager =
    new (std::malloc(sizeof(DefaultAllocator))) DefaultAllocator;
} //__sg_lib
