#pragma once
#include "DefaultAllocator.hpp"
#include "MemoryManager.hpp"
#include "CAllocatorDebugWrapper.hpp"
#include <new>
class CMemoryManagerSwitcher;
class CGlobalManager {
 public:
//  struct SManagerNode {
//    IMemoryManager *current_manager;
//    SManagerNode(IMemoryManager *current_manager, SManagerNode *prev_node)
//        : current_manager(current_manager), prev_node(prev_node) {}
//    SManagerNode *prev_node;
//  };
 private:
  //static SManagerNode *current_node;
  static CMemoryManagerSwitcher *current_manager;
  static bool allocator_track;
 public:
  CGlobalManager() = delete;
  ~CGlobalManager() = delete;
  CGlobalManager(const CGlobalManager &) = delete;
  CGlobalManager &operator=(const CGlobalManager &) = delete;
  static CMemoryManagerSwitcher *TopManager() { return current_manager;}
  static CMemoryManagerSwitcher *SetManager(CMemoryManagerSwitcher *new_manager) {current_manager = new_manager;}
  static void SetTrack(bool track) {allocator_track = track;}
  static bool GetTrack() {return allocator_track;}
//  static void PushAllocator(IMemoryManager *new_manager) {
//    current_node = new(std::malloc(sizeof(SManagerNode))) SManagerNode(new_manager, current_node);
//  }
//  static void PopAllocator() {
//    auto del_node = current_node;
//    current_node = current_node->prev_node;
//    std::free(del_node);
//  }
  static constexpr size_t offset = sizeof(IMemoryManager *) + (sizeof(IMemoryManager *)%alignof(std::max_align_t));
};
CMemoryManagerSwitcher *CGlobalManager::current_manager = nullptr;
bool CGlobalManager::allocator_track = false;
