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
int64_t _830_main(void);

/* Function definitions */
int64_t _830_main(void) {
    int64_t _830_t1;
    int64_t _830_t2;
    struct0 _830_t0;
    int64_t _831_a;
    int64_t _831_b;
    int64_t _830_$retval;
    _830_t1 = 100;
    _830_t2 = 58;
    _830_t0 = (struct0) {_830_t1, _830_t2};
    _831_a = _830_t0._0;
    _831_b = _830_t0._1;
    _830_$retval = $add_int64_t(_831_a, _831_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _830_$retval;
}

int main(void) {
  printf("%ld",_830_main());
  return 0;
}
