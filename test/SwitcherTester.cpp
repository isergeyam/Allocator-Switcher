#include "Global-Switcher.hpp"
#include "CAllocatorWrapper.hpp"
int main() {
  IMemoryManager *m_manager = new CAllocatorWrapper;
  CMemoryManagerSwitcher m_switcher;
  m_switcher.SwitchAllocator(m_manager);
  void *ptr = operator new(10);
  operator delete(ptr);
  delete m_manager;
  return 0;
}
