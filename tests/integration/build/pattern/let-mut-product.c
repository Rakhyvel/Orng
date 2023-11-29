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
int64_t _865_main(void);

/* Function definitions */
int64_t _865_main(void) {
    int64_t _865_t1;
    int64_t _865_t2;
    struct0 _865_t0;
    int64_t _866_x;
    int64_t _866_y;
    int64_t _865_t3;
    int64_t _865_$retval;
    _865_t1 = 3;
    _865_t2 = 40;
    _865_t0 = (struct0) {_865_t1, _865_t2};
    _866_x = _865_t0._0;
    _866_y = _865_t0._1;
    _865_t3 = 100;
    _866_y = $add_int64_t(_866_y, _865_t3, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _865_$retval = $add_int64_t(_866_x, _866_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _865_$retval;
}

int main(void) {
  printf("%ld",_865_main());
  return 0;
}
