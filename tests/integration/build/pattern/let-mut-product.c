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
int64_t _1271_main(void);


/* Function definitions */
int64_t _1271_main(void){
    int64_t _1271_t1;
    int64_t _1271_t2;
    struct struct0 _1271_t0;
    int64_t _1272_x;
    int64_t _1272_y;
    int64_t _1271_t4;
    int64_t _1271_$retval;
    _1271_t1 = 3;
    _1271_t2 = 40;
    _1271_t0 = (struct struct0) {_1271_t1, _1271_t2};
    _1272_x = _1271_t0._0;
    _1272_y = _1271_t0._1;
    _1271_t4 = 100;
    _1272_y = $add_int64_t(_1272_y, _1271_t4, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _1271_$retval = $add_int64_t(_1272_x, _1272_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _1271_$retval;
}


int main(void) {
  printf("%ld",_1271_main());
  return 0;
}
