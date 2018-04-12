//
// Created by sg on 12.04.18.
//

#include "CCurrentMemoryManagerStrategy.hpp"
void *CCurrentMemoryManagerStrategy::Alloc(size_t count) {
  return operator new(count);
}
void CCurrentMemoryManagerStrategy::Free(void *ptr) {
  operator delete(ptr);
}
