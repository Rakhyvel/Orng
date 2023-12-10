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
int64_t _821_main(void);

/* Function definitions */
int64_t _821_main(void) {
    int64_t _821_t1;
    int64_t _821_t2;
    struct0 _821_t0;
    int64_t _822_x;
    int64_t _822_y;
    int64_t _821_t4;
    int64_t _821_t6;
    struct1 _821_t3;
    int64_t _821_$retval;
    _821_t1 = 0;
    _821_t2 = 0;
    _821_t0 = (struct0) {_821_t1, _821_t2};
    _822_x = _821_t0._0;
    _822_y = _821_t0._1;
    _821_t4 = 5;
    _821_t6 = 33;
    _821_t3 = (struct1) {_821_t4, _821_t6};
    _822_x = _821_t3._0;
    _822_y = _821_t3._2;
    _821_$retval = $mult_int64_t(_822_x, _822_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _821_$retval;
}

int main(void) {
  printf("%ld",_821_main());
  return 0;
}
