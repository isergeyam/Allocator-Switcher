#include "Global-Switcher.hpp"
#include "CStackAllocatorWrapper.hpp"
int main() {
  IMemoryManager *m_manager = new CStackAllocatorWrapper;
  CMemoryManagerSwitcher m_switcher;
  m_switcher.SwitchAllocator(m_manager);
  void *ptr = operator new(10);
  operator delete(ptr);
  delete m_manager;
  return 0;
}
