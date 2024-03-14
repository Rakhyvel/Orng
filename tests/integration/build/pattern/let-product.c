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
int64_t _1215_main(void);


/* Function definitions */
int64_t _1215_main(void){
    int64_t _1215_t1;
    int64_t _1215_t2;
    struct struct0 _1215_t0;
    int64_t _1216_x;
    int64_t _1216_y;
    int64_t _1215_t4;
    int64_t _1215_t5;
    int64_t _1215_$retval;
    _1215_t1 = 5;
    _1215_t2 = 30;
    _1215_t0 = (struct struct0) {_1215_t1, _1215_t2};
    _1216_x = _1215_t0._0;
    _1216_y = _1215_t0._1;
    _1215_t4 = $mult_int64_t(_1216_x, _1216_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _1215_t5 = 1;
    _1215_$retval = $add_int64_t(_1215_t4, _1215_t5, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _1215_$retval;
}


int main(void) {
  printf("%ld",_1215_main());
  return 0;
}
