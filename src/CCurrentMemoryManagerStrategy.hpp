//
// Created by sg on 12.04.18.
//
#pragma once
#include "Global-Switcher.hpp"
class CCurrentMemoryManagerStrategy {
  static void* Alloc(size_t count);
  static void Free(void* ptr);

};
void *CCurrentMemoryManagerStrategy::Alloc(size_t count) {
  return operator new(count);
}
void CCurrentMemoryManagerStrategy::Free(void *ptr) {
  operator delete(ptr);
}
