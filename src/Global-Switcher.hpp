#pragma once
#include "GlobalManager.hpp"
#include <cstddef>
void *operator new(size_t count) {
  IMemoryManager *cur_alloc = CGlobalManager::TopAllocator();
#ifdef ALLOCATOR_TRACK
  if(cur_alloc!=nullptr)
    std::cout << "Allocating on " << cur_alloc->Name() << " allocator" << std::endl;
#endif
  void *cur_ptr = (cur_alloc == nullptr) ? std::malloc(count+alignof(std::max_align_t)) : cur_alloc->Alloc(count + alignof(std::max_align_t));
  new(cur_ptr) IMemoryManager*(cur_alloc);
  return static_cast<void *>(static_cast<char *>(cur_ptr) +
                             alignof(std::max_align_t));
}
void operator delete(void *ptr) noexcept {
  auto actual_ptr =
      static_cast<void *>(static_cast<char *>(ptr) - alignof(std::max_align_t));
  IMemoryManager *cur_alloc = *static_cast<IMemoryManager **>(actual_ptr);
#ifdef ALLOCATOR_TRACK
  if(cur_alloc!=nullptr)
    std::cout << "Free on " << cur_alloc->Name() << " allocator" << std::endl;
#endif
  if (cur_alloc == nullptr)
    std::free(actual_ptr);
  else
    cur_alloc->Free(actual_ptr);
}
