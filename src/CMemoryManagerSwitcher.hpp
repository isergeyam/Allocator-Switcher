//
// Created by sg on 12.04.18.
//

#pragma once
#include "GlobalManager.hpp"
class CMemoryManagerSwitcher {
 private:
  size_t counter_;
 public:
  CMemoryManagerSwitcher() : counter_(0) {};
  void SwitchAllocator(IMemoryManager *manager_) {
    CGlobalManager::PushAllocator(manager_);
    ++counter_;
  };
//  void PopAllocator() {
//    if (counter_>0) {
//      CGlobalManager::PopAllocator();
//      --counter_;
//    }
//  }
  ~CMemoryManagerSwitcher() {
    for (size_t i=0;i<counter_;++i)
      CGlobalManager::PopAllocator();
  }
};
