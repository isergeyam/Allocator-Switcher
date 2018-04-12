//
// Created by sg on 12.04.18.
//

#include "CMemoryManagerSwitcher.hpp"
CMemoryManagerSwitcher::CMemoryManagerSwitcher(size_t counter_ = 0) : counter_(counter_) {}
void CMemoryManagerSwitcher::SwitchAllocator(IMemoryManager *manager_) {
  CGlobalManager::PushAllocator(manager_);
  ++counter_;
}
CMemoryManagerSwitcher::~CMemoryManagerSwitcher() {
  for (size_t i=0;i<counter_;++i)
    CGlobalManager::PopAllocator();
}
