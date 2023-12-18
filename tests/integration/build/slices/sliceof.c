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
    int64_t _3;
    int64_t _4;
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _1550_main(void);

/* Function definitions */
int64_t _1550_main(void){
    int64_t _1550_t1;
    int64_t _1550_t2;
    int64_t _1550_t3;
    int64_t _1550_t4;
    int64_t _1550_t5;
    struct0 _1551_x;
    int64_t _1550_t7;
    int64_t _1550_t8;
    int64_t* _1550_t9;
    int64_t _1550_t10;
    struct1 _1551_y;
    int64_t _1550_t11;
    int64_t _1550_t12;
    int64_t _1550_$retval;
    _1550_t1 = 1;
    _1550_t2 = 2;
    _1550_t3 = 3;
    _1550_t4 = 4;
    _1550_t5 = 5;
    _1551_x = (struct0) {_1550_t1, _1550_t2, _1550_t3, _1550_t4, _1550_t5};
    _1550_t7 = 0;
    _1550_t8 = 5;
    $bounds_check(_1550_t7, _1550_t8, "tests/integration/slices/sliceof.orng:4:23:\n    let y: []Int = []x\n                     ^");
    _1550_t9 = ((int64_t*)&_1551_x + _1550_t7);
    _1550_t10 = 5;
    _1551_y = (struct1) {_1550_t9, _1550_t10};
    _1550_t11 = 2;
    _1550_t12 = 77;
    $bounds_check(_1550_t11, _1551_y._1, "tests/integration/slices/sliceof.orng:5:11:\n    y[2] + 77\n         ^");
    _1550_$retval = $add_int64_t(*((int64_t*)_1551_y._0 + _1550_t11), _1550_t12, "tests/integration/slices/sliceof.orng:5:11:\n    y[2] + 77\n         ^");
    return _1550_$retval;
}

int main(void) {
  printf("%ld",_1550_main());
  return 0;
}
