//
// Created by sg on 23.04.18.
//

#ifndef ALLOCATOR_SWITCHER_TESTLIB_HPP
#define ALLOCATOR_SWITCHER_TESTLIB_HPP
#include <vector>
#include <random>
#include <chrono>
template<typename _List>
_List process_operations(size_t n1, size_t n2, const std::vector<int> &mvec) {
  _List mlist;
  auto it = mvec.begin();
  for (size_t i = 0; i < n1; ++i) {
    mlist.push_back(*it);
    ++it;
  }
  for (size_t i = 0; i < n2; ++i) {
    bool del = *it%2;
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
template<typename _Container>
void process_sample(size_t n1, size_t n2, const std::string &str_alloc, const std::string &str_list) {
  CGlobalManager::SetTrack(true);
  void *my_leak = operator new(1); // deliberate memory leak
  CGlobalManager::SetTrack(false);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distr;
  std::vector<int> mvec(n1 + 2*n2);
  std::generate(mvec.begin(), mvec.end(),
                [&distr, &gen]() { return distr(gen); });
  auto begin = std::chrono::steady_clock::now();
  auto l1 =
      process_operations<_Container>(n1, n2, mvec);
  auto end = std::chrono::steady_clock::now();
  std::cout << str_alloc + " allocator " + str_list << ":\t"
            << std::chrono::duration<double, std::milli>(end - begin).count()
            << " ms\n";
}

#endif //ALLOCATOR_SWITCHER_TESTLIB_HPP
