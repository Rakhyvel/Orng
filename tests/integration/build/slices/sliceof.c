/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
    int64_t _4;
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1371_main(void);


/* Function definitions */
int64_t _1371_main(void){
    int64_t _1371_t1;
    int64_t _1371_t2;
    int64_t _1371_t3;
    int64_t _1371_t4;
    int64_t _1371_t5;
    struct struct0 _1372_x;
    int64_t _1371_t8;
    int64_t _1371_t9;
    int64_t* _1371_t10;
    int64_t _1371_t11;
    struct struct1 _1372_y;
    int64_t _1371_t13;
    int64_t _1371_t14;
    int64_t _1371_$retval;
    _1371_t1 = 1;
    _1371_t2 = 2;
    _1371_t3 = 3;
    _1371_t4 = 4;
    _1371_t5 = 5;
    _1372_x = (struct struct0) {_1371_t1, _1371_t2, _1371_t3, _1371_t4, _1371_t5};
    _1371_t8 = 0;
    _1371_t9 = 5;
    $bounds_check(_1371_t8, _1371_t9, "tests/integration/slices/sliceof.orng:4:23:\n    let y: []Int = []x\n                     ^");
    _1371_t10 = ((int64_t*)&_1372_x + _1371_t8);
    _1371_t11 = 5;
    _1372_y = (struct struct1) {_1371_t10, _1371_t11};
    _1371_t13 = 2;
    _1371_t14 = 77;
    $bounds_check(_1371_t13, _1372_y._1, "tests/integration/slices/sliceof.orng:5:11:\n    y[2] + 77\n         ^");
    _1371_$retval = $add_int64_t(*((int64_t*)_1372_y._0 + _1371_t13), _1371_t14, "tests/integration/slices/sliceof.orng:5:11:\n    y[2] + 77\n         ^");
    return _1371_$retval;
}


int main(void) {
  printf("%ld",_1371_main());
  return 0;
}
