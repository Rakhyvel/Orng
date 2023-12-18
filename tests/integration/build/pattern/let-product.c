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
int64_t _1357_main(void);

/* Function definitions */
int64_t _1357_main(void){
    int64_t _1357_t1;
    int64_t _1357_t2;
    struct0 _1357_t0;
    int64_t _1358_x;
    int64_t _1358_y;
    int64_t _1357_t3;
    int64_t _1357_t4;
    int64_t _1357_$retval;
    _1357_t1 = 5;
    _1357_t2 = 30;
    _1357_t0 = (struct0) {_1357_t1, _1357_t2};
    _1358_x = _1357_t0._0;
    _1358_y = _1357_t0._1;
    _1357_t3 = $mult_int64_t(_1358_x, _1358_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _1357_t4 = 1;
    _1357_$retval = $add_int64_t(_1357_t3, _1357_t4, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _1357_$retval;
}

int main(void) {
  printf("%ld",_1357_main());
  return 0;
}
