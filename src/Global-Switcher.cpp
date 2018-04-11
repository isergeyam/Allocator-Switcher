#include "GlobalManager.hpp"
using namespace __sg_lib;
void *operator new(size_t count) {
  IMemoryManager *cur_alloc = CGlobalManager::GetCurrentAllocator();
  void *cur_ptr = cur_alloc->Alloc(count + sizeof(IMemoryManager *));
  *reinterpret_cast<IMemoryManager **>(cur_ptr) = cur_alloc;
  return static_cast<void *>(static_cast<char *>(cur_ptr) +
                             sizeof(IMemoryManager *));
}
void operator delete(void *ptr) noexcept {
  void *actual_ptr =
      static_cast<void *>(static_cast<char *>(ptr) - sizeof(IMemoryManager *));
  IMemoryManager *cur_alloc = *reinterpret_cast<IMemoryManager **>(actual_ptr);
  cur_alloc->Free(actual_ptr);
  return;
}
