//
// Created by sg on 14.04.18.
//
#include "Global-Switcher.hpp"
#include "CAllocatedOn.hpp"
#include "CRuntimeHeapStrategy.hpp"
#include "CCurrentMemoryManagerStrategy.hpp"
#include "XorList.hpp"
#include <gtest/gtest.h>
#include "../../xor-list/StackAllocator.hpp"
class StrategyTest : ::testing::Test {
 public:
  template<typename _Tp>
  class XorListHeapWrapper : public XorList<_Tp>, public CAllocatedOn<CRuntimeHeapStrategy> {};
  template<typename _Tp>
  class XorListManagerWrapper : public XorList<_Tp>, public CAllocatedOn<CCurrentMemoryManagerStrategy> {};
 private:
  CMemoryManagerSwitcher my_switcher;
  StackAllocator<int> m_allocatoru
  XorListHeapWrapper<int> m_heap_list;
  XorListManagerWrapper<int> m_manager_list;
};
int main (int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return  RUN_ALL_TESTS();
}
