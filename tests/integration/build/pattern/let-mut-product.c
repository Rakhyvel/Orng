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
int64_t _783_main(void);

/* Function definitions */
int64_t _783_main(void) {
    int64_t _783_t1;
    int64_t _783_t2;
    struct0 _783_t0;
    int64_t _784_x;
    int64_t _784_y;
    int64_t _783_t3;
    int64_t _783_$retval;
    _783_t1 = 3;
    _783_t2 = 40;
    _783_t0 = (struct0) {_783_t1, _783_t2};
    _784_x = _783_t0._0;
    _784_y = _783_t0._1;
    _783_t3 = 100;
    _784_y = $add_int64_t(_784_y, _783_t3, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _783_$retval = $add_int64_t(_784_x, _784_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _783_$retval;
}

int main(void) {
  printf("%ld",_783_main());
  return 0;
}
