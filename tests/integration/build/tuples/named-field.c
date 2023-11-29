/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _30_main(void);

/* Function definitions */
int64_t _30_main(void) {
    int64_t _30_t1;
    int64_t _30_t2;
    struct0 _31_x;
    int64_t _30_$retval;
    _30_t1 = 20;
    _30_t2 = 3;
    _31_x = (struct0) {_30_t1, _30_t2};
    _30_$retval = $mult_int64_t(_31_x._0, _31_x._1, "tests/integration/tuples/named-field.orng:4:10:\n    x.a * x.b\n        ^");
    return _30_$retval;
}

int main(void) {
  printf("%ld",_30_main());
  return 0;
}
