//
// Created by sg on 12.04.18.
//

#ifndef ALLOCATOR_SWITCHER_CALLOCATEDON_HPP
#define ALLOCATOR_SWITCHER_CALLOCATEDON_HPP
template<typename AllocatorStrategy>
#include <cstddef>
class CAllocatedOn {
  void* operator new(size_t count) {
    return AllocatorStrategy::Alloc(count);
  }
  void operator delete(void *ptr) {
    return AllocatorStrategy::Free(ptr);
  }
};

#endif //ALLOCATOR_SWITCHER_CALLOCATEDON_HPP
