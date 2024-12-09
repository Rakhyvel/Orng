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
    int64_t _2;
};

/* Function forward definitions */
int64_t _1248_main(void);


/* Function definitions */
int64_t _1248_main(void){
    int64_t _1248_t1;
    int64_t _1248_t2;
    int64_t _1248_t3;
    struct struct0 _1248_t0;
    int64_t _1249_a;
    int64_t _1249_c;
    int64_t _1248_$retval;
    _1248_t1 = 100;
    _1248_t2 = 300;
    _1248_t3 = 56;
    _1248_t0 = (struct struct0) {_1248_t1, _1248_t2, _1248_t3};
    _1249_a = _1248_t0._0;
    _1249_c = _1248_t0._2;
    _1248_$retval = $add_int64_t(_1249_a, _1249_c, "tests/integration/pattern/let-ignore-product.orng:4:8:\n    a + c\n      ^");
    return _1248_$retval;
}


int main(void) {
  printf("%ld",_1248_main());
  return 0;
}
