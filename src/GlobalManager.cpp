//
// Created by sg on 11.04.18.
//
#include "GlobalManager.hpp"
namespace __sg_lib {
IMemoryManager *CGlobalManager::GetCurrentAllocator() { return current_manager; }
void CGlobalManager::SetAllocator(IMemoryManager *new_manager) {
  prev_manager = new_manager;
  current_manager = new_manager;
}
IMemoryManager *CGlobalManager::current_manager =
    new (std::malloc(sizeof(CDefaultAllocator))) CDefaultAllocator;
}

