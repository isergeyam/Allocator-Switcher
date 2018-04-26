//
// Created by sg on 26.04.18.
//
#define ALLOCATOR_DEBUG
#define ALLOCATOR_TRACK
#include "XorList.hpp"
#include <chrono>
#include <list>
#include <vector>
#include <random>
#include "CAllocatorWrapper.hpp"
#include "Global-Switcher.hpp"
#include "CMemoryManagerSwitcher.hpp"
#include "TestLib.hpp"
int main() {
  IMemoryManager *m_def_allocator = new CAllocatorDebugWrapper<CDefaultAllocator>;
  IMemoryManager* m_stack_allocator = new CAllocatorDebugWrapper<CStackAllocatorWrapper>;
  CMemoryManagerSwitcher m_switcher;
  m_switcher.SwitchAllocator(m_def_allocator);
  int *ptr1 = new int[10];
  m_switcher.SwitchAllocator(m_stack_allocator);
  int *ptr2 = new int[10];
  delete m_stack_allocator;
  delete m_def_allocator;
  return 0;
}
