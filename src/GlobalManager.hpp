#include "DefaultAllocator.hpp"
#include "MemoryManager.hpp"
#include <new>
namespace __sg_lib {
class CGlobalManager {
private:
  static IMemoryManager *current_manager;
  static IMemoryManager *prev_manager;

public:
  CGlobalManager() = delete;
  ~CGlobalManager() = delete;
  CGlobalManager(const CGlobalManager &) = delete;
  CGlobalManager &operator=(const CGlobalManager &) = delete;
  static IMemoryManager *GetCurrentAllocator();
  static void SetAllocator(IMemoryManager *new_manager);
  friend class CMemorySwitcher;
};
} //__sg_lib
