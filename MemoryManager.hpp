#include <cstdlib>
namespace __sg_lib {
class IMemoryManager {
public:
  virtual void *Alloc(size_t size) = 0;
  virtual void Free(void *ptr) = 0;
}; //__sg_lib
}
