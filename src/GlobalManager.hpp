#pragma once
#include "DefaultAllocator.hpp"
#include "MemoryManager.hpp"
#include "CAllocatorDebugWrapper.hpp"
#include <new>
#include <cstddef>
//class IMemoryManagerSwitcher;
class CGlobalManager {
 public:
 private:
  static IMemoryManager *current_manager;
  static bool allocator_track;
 public:
  CGlobalManager() = delete;
  ~CGlobalManager() = delete;
  CGlobalManager(const CGlobalManager &) = delete;
  CGlobalManager &operator=(const CGlobalManager &) = delete;
  static IMemoryManager *TopManager() { return current_manager; }
  static IMemoryManager *SetManager(IMemoryManager *new_manager) { current_manager = new_manager; }
  static void SetTrack(bool track) { allocator_track = track; }
  static bool GetTrack() { return allocator_track; }
  static constexpr size_t offset = sizeof(IMemoryManager *)
      + ((alignof(std::max_align_t) - (sizeof(IMemoryManager *)%alignof(std::max_align_t)))%alignof(std::max_align_t));
};
IMemoryManager *CGlobalManager::current_manager = nullptr;
bool CGlobalManager::allocator_track = false;
