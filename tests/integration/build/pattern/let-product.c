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
int64_t _868_main(void);

/* Function definitions */
int64_t _868_main(void) {
    int64_t _868_t1;
    int64_t _868_t2;
    struct0 _868_t0;
    int64_t _869_x;
    int64_t _869_y;
    int64_t _868_t3;
    int64_t _868_t4;
    int64_t _868_$retval;
    _868_t1 = 5;
    _868_t2 = 30;
    _868_t0 = (struct0) {_868_t1, _868_t2};
    _869_x = _868_t0._0;
    _869_y = _868_t0._1;
    _868_t3 = $mult_int64_t(_869_x, _869_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _868_t4 = 1;
    _868_$retval = $add_int64_t(_868_t3, _868_t4, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _868_$retval;
}

int main(void) {
  printf("%ld",_868_main());
  return 0;
}
