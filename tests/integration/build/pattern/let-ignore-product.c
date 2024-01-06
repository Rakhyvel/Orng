/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

/* Function forward definitions */
int64_t _1146_main(void);

/* Function definitions */
int64_t _1146_main(void){
    int64_t _1146_t1;
    int64_t _1146_t2;
    int64_t _1146_t3;
    struct struct0 _1146_t0;
    int64_t _1147_a;
    int64_t _1147_c;
    int64_t _1146_$retval;
    _1146_t1 = 100;
    _1146_t2 = 300;
    _1146_t3 = 56;
    _1146_t0 = (struct struct0) {_1146_t1, _1146_t2, _1146_t3};
    _1147_a = _1146_t0._0;
    _1147_c = _1146_t0._2;
    _1146_$retval = $add_int64_t(_1147_a, _1147_c, "tests/integration/pattern/let-ignore-product.orng:4:8:\n    a + c\n      ^");
    return _1146_$retval;
}

int main(void) {
  printf("%ld",_1146_main());
  return 0;
}
