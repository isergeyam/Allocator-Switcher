#ifndef _GLOBAL_MANAGER_HPP_
#define _GLOBAL_MANAGER_HPP_
#include "DefaultAllocator.hpp"
#include "MemoryManager.hpp"
#include <new>
class CGlobalManager {
 public:
  struct SManagerNode{
    IMemoryManager *current_manager;
    SManagerNode(IMemoryManager *current_manager, SManagerNode *prev_node);
    SManagerNode *prev_node;
  };
 private:
  static SManagerNode *current_node;
 public:
  CGlobalManager() = delete;
  ~CGlobalManager() = delete;
  CGlobalManager(const CGlobalManager &) = delete;
  CGlobalManager &operator=(const CGlobalManager &) = delete;
  static IMemoryManager *TopAllocator();
  static void PushAllocator(IMemoryManager *new_manager);
  static void PopAllocator();
};
#endif
