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
int64_t _1209_main(void);


/* Function definitions */
int64_t _1209_main(void){
    int64_t _1209_t1;
    int64_t _1209_t2;
    struct struct0 _1209_t0;
    int64_t _1210_a;
    int64_t _1210_b;
    int64_t _1209_$retval;
    _1209_t1 = 100;
    _1209_t2 = 58;
    _1209_t0 = (struct struct0) {_1209_t1, _1209_t2};
    _1210_a = _1209_t0._0;
    _1210_b = _1209_t0._1;
    _1209_$retval = $add_int64_t(_1210_a, _1210_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _1209_$retval;
}


int main(void) {
  printf("%ld",_1209_main());
  return 0;
}
