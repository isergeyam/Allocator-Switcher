#pragma once
#include "MemoryManager.hpp"
class CDefaultAllocator : public IMemoryManager {
 public:
  void *Alloc(std::size_t __n) override;
  void Free(void *ptr) override;
  const char *Name() override;
  CDefaultAllocator(const CDefaultAllocator &) = delete;
  CDefaultAllocator &operator=(const CDefaultAllocator &) = delete;
  CDefaultAllocator() = default;
};
void *CDefaultAllocator::Alloc(std::size_t __n) { return std::malloc(__n); }
void CDefaultAllocator::Free(void *ptr) { free(ptr); }
const char *CDefaultAllocator::Name() {
  return "default";
}
