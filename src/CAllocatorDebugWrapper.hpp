//
// Created by sg on 14.04.18.
//

#pragma once

#include "MemoryManager.hpp"
#include <map>
#include <iostream>
#include "CMAllocator.hpp"
template<typename _Alloc>
class CAllocatorDebugWrapper : public IMemoryManager {
 private:
  _Alloc *my_manager;
  std::map<void *, std::pair<size_t, size_t>, std::less<>, CMAllocator<void *>> my_map;
  size_t alloc_num;
 public:
  explicit CAllocatorDebugWrapper();
  void *Alloc(size_t size) override;
  void Free(void *ptr) override;
  const char *Name() override;
  ~CAllocatorDebugWrapper() override;
};
template<typename _Alloc>
CAllocatorDebugWrapper<_Alloc>::CAllocatorDebugWrapper()
    : my_manager(new(std::malloc(sizeof(_Alloc))) _Alloc), alloc_num(0) {}
template<typename _Alloc>
void *CAllocatorDebugWrapper<_Alloc>::Alloc(size_t size) {
  void *ans = my_manager->Alloc(size);
#ifdef ALLOCATOR_DEBUG
  my_map.insert(std::make_pair(ans, std::make_pair(++alloc_num, size)));
#endif
  return ans;
}
template<typename _Alloc>
void CAllocatorDebugWrapper<_Alloc>::Free(void *ptr) {
  my_manager->Free(ptr);
#ifdef ALLOCATOR_DEBUG
  my_map.erase(ptr);
#endif
}
template<typename _Alloc>
CAllocatorDebugWrapper<_Alloc>::~CAllocatorDebugWrapper() {
#ifdef ALLOCATOR_DEBUG
  for (auto &it : my_map) {
    std::cerr << "Memory leak of " << it.second.second << " bytes on allocation " << it.second.first << " on address "
              << it.first << std::endl;
  }
#endif
  my_manager->~_Alloc();
  std::free(my_manager);
}
template<typename _Alloc>
const char *CAllocatorDebugWrapper<_Alloc>::Name() {
  return my_manager->Name();
}
