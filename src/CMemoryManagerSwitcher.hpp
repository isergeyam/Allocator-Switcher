//
// Created by sg on 12.04.18.
//

#ifndef ALLOCATOR_SWITCHER_CMEMORYSWITCHER_HPP
#define ALLOCATOR_SWITCHER_CMEMORYSWITCHER_HPP
#include "MemoryManager.hpp"
#include "GlobalManager.hpp"
namespace __sg_lib {
class CMemoryManagerSwitcher {
 private:
  size_t counter_;
 public:
  explicit CMemoryManagerSwitcher(size_t counter_);
  void SwitchAllocator(IMemoryManager *manager_);
  ~CMemoryManagerSwitcher();
};
}
#endif //ALLOCATOR_SWITCHER_CMEMORYSWITCHER_HPP
