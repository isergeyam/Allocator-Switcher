//
// Created by sg on 14.04.18.
//

#pragma once
#include <cstdlib>
template<typename _Tp>
class CMAllocator {
 public:
  using value_type = _Tp;
  template<typename U>
  struct rebind {typedef CMAllocator<U> other;};
  _Tp* allocate(size_t __n) {
    return static_cast<_Tp*>(std::malloc(sizeof(_Tp)*__n));
  }
  void deallocate(_Tp *p, size_t n) {
    std::free(static_cast<void*>(p));
  }
  void construct(_Tp *p, const _Tp &val) {
    new((void*)p) _Tp(val);
  }
  void destroy(_Tp *p) {
    ((_Tp*)p)->~_Tp();
  }
};


