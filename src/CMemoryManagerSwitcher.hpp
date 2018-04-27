//
// Created by sg on 12.04.18.
//

#pragma once
#include "GlobalManager.hpp"
class CMemoryManagerSwitcher {
 private:
  //size_t counter_;
  IMemoryManager *my_manager;
  CMemoryManagerSwitcher *prev_manager;
 public:
  explicit CMemoryManagerSwitcher(IMemoryManager *my_manager) : my_manager(my_manager) {
    prev_manager = CGlobalManager::TopManager();
    CGlobalManager::SetManager(this);
  }
  ~CMemoryManagerSwitcher() {
    CGlobalManager::SetManager(prev_manager);
  }
  IMemoryManager *getMy_manager() const {
    return my_manager;
  }
//  CMemoryManagerSwitcher() : counter_(0) {};
//  void SwitchAllocator(IMemoryManager *manager_) {
//    CGlobalManager::PushAllocator(manager_);
//    ++counter_;
//  };
//  void PopAllocator() {
//    if (counter_>0) {
//      CGlobalManager::PopAllocator();
//      --counter_;
//    }
//  }
//  ~CMemoryManagerSwitcher() {
//    for (size_t i = 0; i < counter_; ++i)
//      CGlobalManager::PopAllocator();
//  }
};
