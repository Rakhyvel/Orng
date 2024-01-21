/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
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
int64_t _1361_main(void);

/* Function definitions */
int64_t _1361_main(void){
    int64_t _1361_t1;
    int64_t _1361_t2;
    int64_t _1361_t3;
    int64_t _1361_t4;
    int64_t _1361_t5;
    struct struct0 _1362_x;
    int64_t _1361_t7;
    int64_t _1361_t8;
    int64_t* _1361_t9;
    int64_t _1361_t10;
    struct struct1 _1362_y;
    int64_t _1361_t11;
    int64_t _1361_t12;
    int64_t _1361_$retval;
    _1361_t1 = 1;
    _1361_t2 = 2;
    _1361_t3 = 3;
    _1361_t4 = 4;
    _1361_t5 = 5;
    _1362_x = (struct struct0) {_1361_t1, _1361_t2, _1361_t3, _1361_t4, _1361_t5};
    _1361_t7 = 0;
    _1361_t8 = 5;
    $bounds_check(_1361_t7, _1361_t8, "tests/integration/slices/sliceof.orng:4:23:\n    let y: []Int = []x\n                     ^");
    _1361_t9 = ((int64_t*)&_1362_x + _1361_t7);
    _1361_t10 = 5;
    _1362_y = (struct struct1) {_1361_t9, _1361_t10};
    _1361_t11 = 2;
    _1361_t12 = 77;
    $bounds_check(_1361_t11, _1362_y._1, "tests/integration/slices/sliceof.orng:5:11:\n    y[2] + 77\n         ^");
    _1361_$retval = $add_int64_t(*((int64_t*)_1362_y._0 + _1361_t11), _1361_t12, "tests/integration/slices/sliceof.orng:5:11:\n    y[2] + 77\n         ^");
    return _1361_$retval;
}

int main(void) {
  printf("%ld",_1361_main());
  return 0;
}
