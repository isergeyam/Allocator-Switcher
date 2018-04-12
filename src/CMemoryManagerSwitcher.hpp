//
// Created by sg on 12.04.18.
//

#ifndef ALLOCATOR_SWITCHER_CMEMORYSWITCHER_HPP
#define ALLOCATOR_SWITCHER_CMEMORYSWITCHER_HPP
#include "GlobalManager.hpp"
class CMemoryManagerSwitcher {
 private:
  size_t counter_;
 public:
  CMemoryManagerSwitcher() = default;
  void SwitchAllocator(IMemoryManager *manager_);
  ~CMemoryManagerSwitcher();
};
#endif //ALLOCATOR_SWITCHER_CMEMORYSWITCHER_HPP
