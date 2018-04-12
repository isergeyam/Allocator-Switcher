#include "../src/Global-Switcher.hpp"
#include <iostream>
#include <iterator>
#include <vector>
int main() {
  void *raw_ptr = ::operator new(sizeof(std::vector<int>));
  std::vector<int> *ptr = new (raw_ptr) std::vector<int>(10, 2);
  std::copy(ptr->begin(), ptr->end(),
            std::ostream_iterator<int>(std::cout, " "));
  delete ptr;
  return 0;
}
