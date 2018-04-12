//
// Created by sg on 12.04.18.
//

#include "CStackAllocatorWrapper.hpp"
template<typename _Tp>
void *CStackAllocatorWrapper<_Tp>::Alloc(size_t size) {
  return m_allocator->allocate(size);
}
template<typename _Tp>
void CStackAllocatorWrapper<_Tp>::Free(void *ptr) {
  m_allocator->deallocate(ptr, 0);
}
template<typename _Tp>
CStackAllocatorWrapper<_Tp>::~CStackAllocatorWrapper() {
  std::free(m_allocator);
}
template<typename _Tp>
CStackAllocatorWrapper<_Tp>::CStackAllocatorWrapper() {
  m_allocator = new(std::malloc(sizeof(StackAllocator<_Tp>))) StackAllocator<_Tp>;
}

