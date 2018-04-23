//
// Created by sg on 14.04.18.
//
#include "Global-Switcher.hpp"
#include "CAllocatedOn.hpp"
#include "CRuntimeHeapStrategy.hpp"
#include "CCurrentMemoryManagerStrategy.hpp"
#include <gtest/gtest.h>
#include <CAllocatorWrapper.hpp>
#include "../../xor-list/XorList.hpp"
#include "TestLib.hpp"
template<typename _Tp>
class XorListHeapWrapper : public CAllocatedOn<CRuntimeHeapStrategy>, public XorList<_Tp> {};
template<typename _Tp>
class XorListManagerWrapper : public CAllocatedOn<CCurrentMemoryManagerStrategy>, public XorList<_Tp> {};
class StrategyTest : public ::testing::Test {
 public:
  CMemoryManagerSwitcher my_switcher;
  IMemoryManager *m_allocator;
};
TEST_F(StrategyTest, GenetalStrategyTest) {
  m_allocator = m_alloc<CStackAllocatorWrapper>();
  my_switcher.SwitchAllocator(m_allocator);
  process_sample<XorListHeapWrapper<int>>(1000, 1000, "default", "xorlist");
  process_sample<XorListManagerWrapper<int>>(1000, 1000, "stack", "xorlist");
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
