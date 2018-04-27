//
// Created by sg on 12.04.18.
//

#pragma once
#include "GlobalManager.hpp"
class CMemoryManagerSwitcher {
 private:
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
};
