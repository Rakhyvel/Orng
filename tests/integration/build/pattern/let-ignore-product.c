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
    int64_t _2;
} struct0;

/* Function forward definitions */
int64_t _844_main(void);

/* Function definitions */
int64_t _844_main(void) {
    int64_t _844_t1;
    int64_t _844_t2;
    int64_t _844_t3;
    struct0 _844_t0;
    int64_t _845_a;
    int64_t _845_c;
    int64_t _844_$retval;
    _844_t1 = 100;
    _844_t2 = 300;
    _844_t3 = 56;
    _844_t0 = (struct0) {_844_t1, _844_t2, _844_t3};
    _845_a = _844_t0._0;
    _845_c = _844_t0._2;
    _844_$retval = $add_int64_t(_845_a, _845_c, "tests/integration/pattern/let-ignore-product.orng:4:8:\n    a + c\n      ^");
    return _844_$retval;
}

int main(void) {
  printf("%ld",_844_main());
  return 0;
}
