#include "DefaultAllocator.hpp"
#include "MemoryManager.hpp"
#include <new>
class CGlobalManager {
private:
  static SManagerNode *current_node;
public:
  struct SManagerNode{
    IMemoryManager *current_manager;
    SManagerNode(IMemoryManager *current_manager, SManagerNode *prev_node);
    SManagerNode *prev_node;
  };
  CGlobalManager() = delete;
  ~CGlobalManager() = delete;
  CGlobalManager(const CGlobalManager &) = delete;
  CGlobalManager &operator=(const CGlobalManager &) = delete;
  static IMemoryManager *TopAllocator();
  static void PushAllocator(IMemoryManager *new_manager);
  static void PopAllocator();
};
