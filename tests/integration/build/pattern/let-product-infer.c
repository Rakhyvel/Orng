/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1175_main(void);


/* Function definitions */
int64_t _1175_main(void){
    int64_t _1175_t1;
    int64_t _1175_t2;
    struct struct0 _1175_t0;
    int64_t _1176_a;
    int64_t _1176_b;
    int64_t _1175_$retval;
    _1175_t1 = 100;
    _1175_t2 = 58;
    _1175_t0 = (struct struct0) {_1175_t1, _1175_t2};
    _1176_a = _1175_t0._0;
    _1176_b = _1175_t0._1;
    _1175_$retval = $add_int64_t(_1176_a, _1176_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _1175_$retval;
}


int main(void) {
  printf("%ld",_1175_main());
  return 0;
}
