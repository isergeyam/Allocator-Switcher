//
// Created by sg on 12.04.18.
//

#ifndef ALLOCATOR_SWITCHER_CALLOCATEDON_HPP
#define ALLOCATOR_SWITCHER_CALLOCATEDON_HPP
#include <cstddef>
template<typename AllocatorStrategy>
class CAllocatedOn {
 public:
  void *operator new(size_t count) {
    return AllocatorStrategy::Alloc(count);
  }
  void operator delete(void *ptr) {
    AllocatorStrategy::Free(ptr);
  }
};

#endif //ALLOCATOR_SWITCHER_CALLOCATEDON_HPP
