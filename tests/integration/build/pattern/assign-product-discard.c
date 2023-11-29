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
int64_t _840_main(void);

/* Function definitions */
int64_t _840_main(void) {
    int64_t _840_t1;
    int64_t _840_t2;
    struct0 _840_t0;
    int64_t _841_x;
    int64_t _841_y;
    int64_t _840_t4;
    int64_t _840_t6;
    struct1 _840_t3;
    int64_t _840_$retval;
    _840_t1 = 0;
    _840_t2 = 0;
    _840_t0 = (struct0) {_840_t1, _840_t2};
    _841_x = _840_t0._0;
    _841_y = _840_t0._1;
    _840_t4 = 5;
    _840_t6 = 33;
    _840_t3 = (struct1) {_840_t4, _840_t6};
    _841_x = _840_t3._0;
    _841_y = _840_t3._2;
    _840_$retval = $mult_int64_t(_841_x, _841_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _840_$retval;
}

int main(void) {
  printf("%ld",_840_main());
  return 0;
}
