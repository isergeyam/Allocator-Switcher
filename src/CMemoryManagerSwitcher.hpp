//
// Created by sg on 12.04.18.
//

#pragma once
#include "GlobalManager.hpp"
class CMemoryManagerSwitcher {
 private:
  IMemoryManager *prev_manager;
  //CMemoryManagerSwitcher *prev_manager;
 public:
  explicit CMemoryManagerSwitcher(IMemoryManager *my_manager) /*: my_manager(my_manager)*/ {
    prev_manager = CGlobalManager::TopManager();
    CGlobalManager::SetManager(my_manager);
  }
  ~CMemoryManagerSwitcher() {
    CGlobalManager::SetManager(prev_manager);
  }
};
