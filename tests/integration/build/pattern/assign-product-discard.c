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

typedef struct {
    int64_t _0;
    int64_t _2;
} struct1;

/* Function forward definitions */
int64_t _848_main(void);

/* Function definitions */
int64_t _848_main(void) {
    int64_t _848_t1;
    int64_t _848_t2;
    struct0 _848_t0;
    int64_t _849_x;
    int64_t _849_y;
    int64_t _848_t4;
    int64_t _848_t6;
    struct1 _848_t3;
    int64_t _848_$retval;
    _848_t1 = 0;
    _848_t2 = 0;
    _848_t0 = (struct0) {_848_t1, _848_t2};
    _849_x = _848_t0._0;
    _849_y = _848_t0._1;
    _848_t4 = 5;
    _848_t6 = 33;
    _848_t3 = (struct1) {_848_t4, _848_t6};
    _849_x = _848_t3._0;
    _849_y = _848_t3._2;
    _848_$retval = $mult_int64_t(_849_x, _849_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _848_$retval;
}

int main(void) {
  printf("%ld",_848_main());
  return 0;
}
