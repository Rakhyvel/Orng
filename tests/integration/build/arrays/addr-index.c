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
    int64_t _3;
};

/* Function forward definitions */
int64_t _15_main(void);


/* Function definitions */
int64_t _15_main(void){
    int64_t _15_t1;
    int64_t _15_t2;
    int64_t _15_t3;
    int64_t _15_t4;
    struct struct0 _16_x;
    int64_t _15_t6;
    int64_t _15_t7;
    int64_t* _16_y;
    int64_t _15_t11;
    int64_t _15_t12;
    int64_t _15_$retval;
    _15_t1 = 1;
    _15_t2 = 2;
    _15_t3 = 3;
    _15_t4 = 4;
    _16_x = (struct struct0) {_15_t1, _15_t2, _15_t3, _15_t4};
    _15_t6 = 0;
    _15_t7 = 4;
    $bounds_check(_15_t6, _15_t7, "tests/integration/arrays/addr-index.orng:4:24:\n    let y: &mut Int = &mut x[0]\n                      ^");
    _16_y = ((int64_t*)&_16_x + _15_t6);
    *_16_y = 63;
    _15_t11 = 0;
    _15_t12 = 4;
    $bounds_check(_15_t11, _15_t12, "tests/integration/arrays/addr-index.orng:2:8:\nfn main() -> Int {\n      ^");
    _15_$retval = *((int64_t*)&_16_x + _15_t11);
    return _15_$retval;
}


int main(void) {
  printf("%ld",_15_main());
  return 0;
}
