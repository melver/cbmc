#include <stdint.h>

union U
{
  double f;
  int64_t bv;
};

int main()
{
  double d;
  union U u, v = {d};
  u.f = d;
  __CPROVER_assert(u.bv == v.bv, "writing a double member");

  int64_t x;
  // the bit patterns of positive, finite doubles
  __CPROVER_assume(x > 0 && x < 0x7FF0000000000000);
  union U w;
  w.bv = x;
  __CPROVER_assert(w.f > 0, "reading a double member");

  return 0;
}
