//
// Created by sg on 12.04.18.
//

#ifndef ALLOCATOR_SWITCHER_CCURRENTMEMORYMANAGERSTRATEGY_HPP
#define ALLOCATOR_SWITCHER_CCURRENTMEMORYMANAGERSTRATEGY_HPP
#include "Global-Switcher.hpp"
#include <cstddef>
class CCurrentMemoryManagerStrategy {
  static void* Alloc(size_t count);
  static void Free(void* ptr);

};

#endif //ALLOCATOR_SWITCHER_CCURRENTMEMORYMANAGERSTRATEGY_HPP
