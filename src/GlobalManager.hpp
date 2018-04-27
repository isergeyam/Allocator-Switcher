#pragma once
#include "DefaultAllocator.hpp"
#include "MemoryManager.hpp"
#include "CAllocatorDebugWrapper.hpp"
#include <new>
class CMemoryManagerSwitcher;
class CGlobalManager {
 public:
 private:
  static CMemoryManagerSwitcher *current_manager;
  static bool allocator_track;
 public:
  CGlobalManager() = delete;
  ~CGlobalManager() = delete;
  CGlobalManager(const CGlobalManager &) = delete;
  CGlobalManager &operator=(const CGlobalManager &) = delete;
  static CMemoryManagerSwitcher *TopManager() { return current_manager; }
  static CMemoryManagerSwitcher *SetManager(CMemoryManagerSwitcher *new_manager) { current_manager = new_manager; }
  static void SetTrack(bool track) { allocator_track = track; }
  static bool GetTrack() { return allocator_track; }
  static constexpr size_t offset = sizeof(IMemoryManager *) + (sizeof(IMemoryManager *)%alignof(std::max_align_t));
};
CMemoryManagerSwitcher *CGlobalManager::current_manager = nullptr;
bool CGlobalManager::allocator_track = false;
