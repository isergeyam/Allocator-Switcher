//
// Created by sg on 12.04.18.
//

#ifndef ALLOCATOR_SWITCHER_CSTACKALLOCATORWRAPPER_HPP
#define ALLOCATOR_SWITCHER_CSTACKALLOCATORWRAPPER_HPP
#include "StackAllocator.hpp"
#include "MemoryManager.hpp"
template<typename _Tp>
class CStackAllocatorWrapper : public IMemoryManager {
 public:
  StackAllocator<_Tp> *m_allocator;
 private:

};

#endif //ALLOCATOR_SWITCHER_CSTACKALLOCATORWRAPPER_HPP
