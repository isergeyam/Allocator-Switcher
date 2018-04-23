//
// Created by sg on 12.04.18.
//

#pragma once
#include "../Stack-Allocator/src/StackAllocator.hpp"
#include "MemoryManager.hpp"
#include <functional>
template<template<class> class _Allocator>
class CAllocatorWrapper : public IMemoryManager {
 private:
  _Allocator<char> *m_allocator;
  std::reference_wrapper<int> m_alloc_num;
  void free_variables();
  using _Self = CAllocatorWrapper<_Allocator>;
 public:
  CAllocatorWrapper();
  void *Alloc(size_t size) override;
  void Free(void *ptr) override;
  ~CAllocatorWrapper() override;
  CAllocatorWrapper &operator=(const CAllocatorWrapper &other);
  CAllocatorWrapper(const CAllocatorWrapper &other);
};
template<template<class> class _Allocator>
void *CAllocatorWrapper<_Allocator>::Alloc(size_t size) {
  return m_allocator->allocate(size);
}
template<template<class> class _Allocator>
void CAllocatorWrapper<_Allocator>::Free(void *ptr) {
  m_allocator->deallocate(reinterpret_cast<char *>(ptr), 0);
}
template<template<class> class _Allocator>
CAllocatorWrapper<_Allocator>::~CAllocatorWrapper() {
  free_variables();
}
template<template<class> class _Allocator>
void CAllocatorWrapper<_Allocator>::free_variables() {
  if (m_alloc_num==0) {
    m_allocator->~StackAllocator();
    free(m_allocator);
    free(&m_alloc_num.get());
  } else
    --m_alloc_num;
}
template<template<class> class _Allocator>
CAllocatorWrapper<_Allocator>::CAllocatorWrapper() : m_alloc_num(*(m_alloc<int>())) {
  m_allocator = m_alloc<_Allocator<char>>();
}
template<template<class> class _Allocator>
CAllocatorWrapper<_Allocator> &CAllocatorWrapper<_Allocator>::operator=(const _Self &other) {
  free_variables();
  m_allocator = other.m_allocator;
  m_alloc_num = other.m_alloc_num;
}
template<template<class> class _Allocator>
CAllocatorWrapper<_Allocator>::CAllocatorWrapper(const _Self &other) : m_allocator(other.m_allocator),
                                                                       m_alloc_num(other.m_alloc_num) {
  ++m_alloc_num;
}
using CStackAllocatorWrapper = CAllocatorWrapper<StackAllocator>;
