#pragma once
#include "GlobalManager.hpp"
#include "CMemoryManagerSwitcher.hpp"
#include <cstddef>
void *operator new(size_t count) {
  IMemoryManager
      *cur_alloc = (CGlobalManager::TopManager()==nullptr) ? nullptr : CGlobalManager::TopManager();
  if (CGlobalManager::GetTrack()) {
    if (cur_alloc!=nullptr)
      std::cout << "Allocating on " << cur_alloc->Name() << " allocator" << std::endl;
  }
  size_t actual_alloc = count + CGlobalManager::offset;
  void *cur_ptr = (cur_alloc==nullptr) ? std::malloc(actual_alloc) : cur_alloc->Alloc(actual_alloc);
  new(cur_ptr) IMemoryManager *(cur_alloc);
  return static_cast<void *>(static_cast<char *>(cur_ptr) + CGlobalManager::offset);
}
void operator delete(void *ptr) noexcept {
  auto actual_ptr =
      static_cast<void *>(static_cast<char *>(ptr) - CGlobalManager::offset);
  IMemoryManager *cur_alloc = *static_cast<IMemoryManager **>(actual_ptr);
  if (CGlobalManager::GetTrack()) {
    if (cur_alloc!=nullptr)
      std::cout << "Free on " << cur_alloc->Name() << " allocator" << std::endl;
  }
  if (cur_alloc==nullptr)
    std::free(actual_ptr);
  else
    cur_alloc->Free(actual_ptr);
}
