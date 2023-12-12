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
int64_t _869_main(void);

/* Function definitions */
int64_t _869_main(void) {
    int64_t _869_t1;
    int64_t _869_t2;
    struct0 _869_t0;
    int64_t _870_x;
    int64_t _870_y;
    int64_t _869_t3;
    int64_t _869_$retval;
    _869_t1 = 3;
    _869_t2 = 40;
    _869_t0 = (struct0) {_869_t1, _869_t2};
    _870_x = _869_t0._0;
    _870_y = _869_t0._1;
    _869_t3 = 100;
    _870_y = $add_int64_t(_870_y, _869_t3, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _869_$retval = $add_int64_t(_870_x, _870_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _869_$retval;
}

int main(void) {
  printf("%ld",_869_main());
  return 0;
}
