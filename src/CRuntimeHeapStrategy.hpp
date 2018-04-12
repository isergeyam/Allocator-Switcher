//
// Created by sg on 12.04.18.
//

#ifndef ALLOCATOR_SWITCHER_CRUNTIMEHEAP_HPP
#define ALLOCATOR_SWITCHER_CRUNTIMEHEAP_HPP
#include <cstdlib>
class CRuntimeHeapStrategy {
  static void* Alloc(size_t count);
  static void Free(void* ptr);
};

#endif //ALLOCATOR_SWITCHER_CRUNTIMEHEAP_HPP
