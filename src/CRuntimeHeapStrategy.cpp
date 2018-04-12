//
// Created by sg on 12.04.18.
//

#include "CRuntimeHeapStrategy.hpp"
void *CRuntimeHeapStrategy::Alloc(size_t count) {
  return std::malloc(count);
}
void CRuntimeHeapStrategy::Free(void * ptr) {
  std::free(ptr);
}
