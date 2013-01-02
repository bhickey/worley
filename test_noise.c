#include "worley.h"

#include <assert.h>
#include <iostream>
#include <stdlib.h>

int main()
{
  srand(0);
  size_t max_order = 4;
  double at[3] = {0, 0, 0};
  double *F = new double[max_order];
  double (*delta)[3] = new double[max_order][3];
  uint32_t *ID = new uint32_t[max_order];
  for (int trials = 0; trials < 1000; ++trials)
  {
    at[0] += 10 * ((rand() % 100) / 100.0 - 0.5);
    at[1] += 10 * ((rand() % 100) / 100.0 - 0.5);
    at[2] += 10 * ((rand() % 100) / 100.0 - 0.5);
    Worley(at, max_order, F, delta, ID);
    for (int i = 0; i < max_order - 1; ++i)
        assert(F[i] <= F[i+1]);
  }
  return 0;
}
