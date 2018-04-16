#define ALLOCATOR_DEBUG
#include "XorList.hpp"
#include <chrono>
#include <list>
#include <vector>
#include <random>
#include "CAllocatorWrapper.hpp"
#include "Global-Switcher.hpp"
template <typename _List>
_List process_operations(size_t n1, size_t n2, const std::vector<int> &mvec) {
  _List mlist;
  auto it = mvec.begin();
  for (size_t i = 0; i < n1; ++i) {
    mlist.push_back(*it);
    ++it;
  }
  for (size_t i = 0; i < n2; ++i) {
    bool del = *it % 2;
    ++it;
    if (del && !mlist.empty())
      mlist.pop_back();
    else {
      mlist.push_back(*it);
      ++it;
    }
  }
  return mlist;
}
template <template <class, class> class _Container>
void process_sample(size_t n1, size_t n2, const std::string &str_alloc, const std::string &str_list) {
  auto my_leak = new int; // deliberate memory leak
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distr;
  std::vector<int> mvec(n1 + 2 * n2);
  std::generate(mvec.begin(), mvec.end(),
                [&distr, &gen]() { return distr(gen); });
  auto begin = std::chrono::steady_clock::now();
  auto l1 =
      process_operations<_Container<int, std::allocator<int>>>(n1, n2, mvec);
  auto end = std::chrono::steady_clock::now();
  std::cout << str_alloc + " allocator " + str_list << ":\t"
            << std::chrono::duration<double, std::milli>(end - begin).count()
            << " ms\n";
}
int main() {
  size_t n1, n2;
  std::cin >> n1 >> n2;
  IMemoryManager *m_def_allocator = new CAllocatorDebugWrapper<CDefaultAllocator>;
  IMemoryManager* m_stack_allocator = new CAllocatorDebugWrapper<CStackAllocatorWrapper>;
  {
    CMemoryManagerSwitcher m_switcher;
    m_switcher.SwitchAllocator(m_def_allocator);
    process_sample<std::list>(n1, n2, "default", "list");
    process_sample<XorList>(n1, n2, "default", "xorlist");
    m_switcher.SwitchAllocator(m_stack_allocator);
    process_sample<std::list>(n1, n2, "stack", "list");
    process_sample<XorList>(n1, n2, "stack", "xorlist");
  }
  delete m_stack_allocator;
  delete m_def_allocator;
  return 0;
}
