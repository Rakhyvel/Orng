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
int64_t _26_main(void);

/* Function definitions */
int64_t _26_main(void) {
    int64_t _26_t1;
    double _26_t2;
    struct0 _27_x;
    int64_t _26_$retval;
    _26_t1 = 137;
    _26_t2 = 0;
    _27_x = (struct0) {_26_t1, _26_t2};
    _26_$retval = _27_x._0;
    return _26_$retval;
}

int main(void) {
  printf("%ld",_26_main());
  return 0;
}
