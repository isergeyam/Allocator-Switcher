//
// Created by sg on 12.04.18.
//

#pragma once
#include <cstdlib>
class CRuntimeHeapStrategy {
  static void *Alloc(size_t count);
  static void Free(void *ptr);
};
void *CRuntimeHeapStrategy::Alloc(size_t count) {
  return std::malloc(count);
}
void CRuntimeHeapStrategy::Free(void *ptr) {
  std::free(ptr);
}
