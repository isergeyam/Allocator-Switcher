//
// Created by sg on 12.04.18.
//

#pragma once
#include "StackAllocator.hpp"
#include "MemoryManager.hpp"
class CStackAllocatorWrapper : public IMemoryManager {
 private:
  StackAllocator<char> *m_allocator;
 public:
  CStackAllocatorWrapper();
  void *Alloc(size_t size) override;
  void Free(void *ptr) override;
  ~CStackAllocatorWrapper() override;
};
void *CStackAllocatorWrapper::Alloc(size_t size) {
  return m_allocator->allocate(size);
}
void CStackAllocatorWrapper::Free(void *ptr) {
  m_allocator->deallocate(reinterpret_cast<char*>(ptr), 0);
}
CStackAllocatorWrapper::~CStackAllocatorWrapper() {
  m_allocator->~StackAllocator();
  std::free(m_allocator);
}
CStackAllocatorWrapper::CStackAllocatorWrapper() {
  m_allocator = new(std::malloc(sizeof(StackAllocator<char>))) StackAllocator<char>;
}

