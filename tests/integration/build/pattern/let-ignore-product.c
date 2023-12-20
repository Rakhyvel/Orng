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
int64_t _1130_main(void);

/* Function definitions */
int64_t _1130_main(void){
    int64_t _1130_t1;
    int64_t _1130_t2;
    int64_t _1130_t3;
    struct0 _1130_t0;
    int64_t _1131_a;
    int64_t _1131_c;
    int64_t _1130_$retval;
    _1130_t1 = 100;
    _1130_t2 = 300;
    _1130_t3 = 56;
    _1130_t0 = (struct0) {_1130_t1, _1130_t2, _1130_t3};
    _1131_a = _1130_t0._0;
    _1131_c = _1130_t0._2;
    _1130_$retval = $add_int64_t(_1131_a, _1131_c, "tests/integration/pattern/let-ignore-product.orng:4:8:\n    a + c\n      ^");
    return _1130_$retval;
}

int main(void) {
  printf("%ld",_1130_main());
  return 0;
}
