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
int64_t _1233_main(void);

/* Function definitions */
int64_t _1233_main(void){
    int64_t _1233_t1;
    int64_t _1233_t2;
    int64_t _1233_t3;
    struct0 _1233_t0;
    int64_t _1234_a;
    int64_t _1234_c;
    int64_t _1233_$retval;
    _1233_t1 = 100;
    _1233_t2 = 300;
    _1233_t3 = 56;
    _1233_t0 = (struct0) {_1233_t1, _1233_t2, _1233_t3};
    _1234_a = _1233_t0._0;
    _1234_c = _1233_t0._2;
    _1233_$retval = $add_int64_t(_1234_a, _1234_c, "tests/integration/pattern/let-ignore-product.orng:4:8:\n    a + c\n      ^");
    return _1233_$retval;
}

int main(void) {
  printf("%ld",_1233_main());
  return 0;
}
