#pragma once
#include "DefaultAllocator.hpp"
#include "MemoryManager.hpp"
#include <new>
class CGlobalManager {
 public:
  struct SManagerNode{
    IMemoryManager *current_manager;
    SManagerNode(IMemoryManager *current_manager, SManagerNode *prev_node) : current_manager(current_manager), prev_node(prev_node) {}
    SManagerNode *prev_node;
  };
 private:
  static SManagerNode *current_node;
 public:
  CGlobalManager() = delete;
  ~CGlobalManager() = delete;
  CGlobalManager(const CGlobalManager &) = delete;
  CGlobalManager &operator=(const CGlobalManager &) = delete;
  static IMemoryManager *TopAllocator() { return current_node->current_manager; }
  static void PushAllocator(IMemoryManager *new_manager) {
    current_node = new(std::malloc(sizeof(SManagerNode))) SManagerNode(new_manager, current_node);
  }
  static void PopAllocator() {
    current_node = current_node->prev_node;
  }
};
CGlobalManager::SManagerNode* CGlobalManager::current_node =
    new (std::malloc(sizeof(SManagerNode))) SManagerNode(new (std::malloc(sizeof(CDefaultAllocator))) CDefaultAllocator, nullptr);
