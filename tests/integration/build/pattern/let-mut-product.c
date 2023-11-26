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
int64_t _752_main(void);

/* Function definitions */
int64_t _752_main(void) {
    int64_t _752_t1;
    int64_t _752_t2;
    struct0 _752_t0;
    int64_t _753_x;
    int64_t _753_y;
    int64_t _752_t3;
    int64_t _752_$retval;
    _752_t1 = 3;
    _752_t2 = 40;
    _752_t0 = (struct0) {_752_t1, _752_t2};
    _753_x = _752_t0._0;
    _753_y = _752_t0._1;
    _752_t3 = 100;
    _753_y = $add_int64_t(_753_y, _752_t3, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _752_$retval = $add_int64_t(_753_x, _753_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _752_$retval;
}

int main(void) {
  printf("%ld",_752_main());
  return 0;
}
