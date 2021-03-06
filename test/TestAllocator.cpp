#define ALLOCATOR_DEBUG
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
  size_t n1 = 1000000, n2 = 1000000;
  IMemoryManager *m_def_allocator = new CAllocatorDebugWrapper<CDefaultAllocator>;
  IMemoryManager *m_stack_allocator = new CAllocatorDebugWrapper<CStackAllocatorWrapper>;
  {
    CMemoryManagerSwitcher m_switcher(m_def_allocator);
    process_sample<std::list<int>>(n1, n2, "default", "list");
    process_sample<XorList<int>>(n1, n2, "default", "xorlist");
  }
  {
    CMemoryManagerSwitcher m_switcher(m_stack_allocator);
    process_sample<std::list<int>>(n1, n2, "stack", "list");
    process_sample<XorList<int>>(n1, n2, "stack", "xorlist");
  }
  delete m_stack_allocator;
  delete m_def_allocator;
  return 0;
}
