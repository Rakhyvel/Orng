/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    double _1;
} struct0;

/* Function forward definitions */
int64_t _285_main(void);

/* Function definitions */
int64_t _285_main(void) {
    int64_t _285_t1;
    double _285_t2;
    struct0 _286_x;
    int64_t _285_$retval;
    _285_t1 = 137;
    _285_t2 = 0.0e+00;
    _286_x = (struct0) {_285_t1, _285_t2};
    _285_$retval = _286_x._0;
    return _285_$retval;
}

int main(void) {
  printf("%ld",_285_main());
  return 0;
}
