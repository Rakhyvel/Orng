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
int64_t _1103_main(void);

/* Function definitions */
int64_t _1103_main(void){
    int64_t _1103_t1;
    int64_t _1103_t2;
    struct0 _1103_t0;
    int64_t _1104_a;
    int64_t _1104_b;
    int64_t _1103_$retval;
    _1103_t1 = 100;
    _1103_t2 = 58;
    _1103_t0 = (struct0) {_1103_t1, _1103_t2};
    _1104_a = _1103_t0._0;
    _1104_b = _1103_t0._1;
    _1103_$retval = $add_int64_t(_1104_a, _1104_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _1103_$retval;
}

int main(void) {
  printf("%ld",_1103_main());
  return 0;
}
