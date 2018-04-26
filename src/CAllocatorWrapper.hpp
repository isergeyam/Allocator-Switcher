//
// Created by sg on 12.04.18.
//

#pragma once
#include "../Stack-Allocator/src/StackAllocator.hpp"
#include "MemoryManager.hpp"
class CStackAllocatorWrapper : public IMemoryManager {
 private:
  StackRealAllocator m_alloc;
 public:
  void* Alloc(size_t num_) override {
    return m_alloc.allocate(num_);
  }
  void Free(void *ptr) override {
    (void) ptr;
  }
  CStackAllocatorWrapper(const CStackAllocatorWrapper&) = delete;
  CStackAllocatorWrapper& operator=(const CStackAllocatorWrapper&) = delete;
  CStackAllocatorWrapper() = default;
};
