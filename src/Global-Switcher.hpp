#pragma once
#include "GlobalManager.hpp"
#include "CMemoryManagerSwitcher.hpp"
void *operator new(size_t count) {
  IMemoryManager *cur_alloc = CGlobalManager::TopAllocator();
  void *cur_ptr = cur_alloc->Alloc(count + sizeof(IMemoryManager *));
  new(cur_ptr) IMemoryManager*(cur_alloc);
  return reinterpret_cast<void *>(reinterpret_cast<char *>(cur_ptr) +
                             sizeof(IMemoryManager *));
}
void operator delete(void *ptr) noexcept {
  auto actual_ptr =
      reinterpret_cast<void *>(reinterpret_cast<char *>(ptr) - sizeof(IMemoryManager *));
  IMemoryManager *cur_alloc = *reinterpret_cast<IMemoryManager **>(actual_ptr);
  cur_alloc->Free(actual_ptr);
}
