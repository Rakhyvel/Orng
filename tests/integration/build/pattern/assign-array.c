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

typedef struct struct0(*function1)(void);

/* Function forward definitions */
int64_t _1195_main(void);
struct struct0 _1197_get_array(void);


/* Function definitions */
int64_t _1195_main(void){
    int64_t _1195_t1;
    int64_t _1195_t2;
    int64_t _1195_t3;
    struct struct0 _1196_x;
    function1 _1195_t5;
    struct struct0 _1195_t6;
    int64_t _1195_t9;
    int64_t _1195_t10;
    int64_t _1195_t13;
    int64_t _1195_t14;
    int64_t _1195_t17;
    int64_t _1195_t18;
    int64_t _1195_t19;
    int64_t _1195_t20;
    int64_t _1195_t21;
    int64_t _1195_t22;
    int64_t _1195_t23;
    int64_t _1195_t24;
    int64_t _1195_t25;
    int64_t _1195_$retval;
    _1195_t1 = 0;
    _1195_t2 = 0;
    _1195_t3 = 0;
    _1196_x = (struct struct0) {_1195_t1, _1195_t2, _1195_t3};
    _1195_t5 = (function1) _1197_get_array;
    $lines[$line_idx++] = "tests/integration/pattern/assign-array.orng:4:36:\n    (x[0], x[1], x[2]) = get_array()\n                                  ^";
    _1195_t6 = _1195_t5();
    $line_idx--;
    _1195_t9 = 0;
    _1195_t10 = 3;
    $bounds_check(_1195_t9, _1195_t10, "tests/integration/pattern/assign-array.orng:4:8:\n    (x[0], x[1], x[2]) = get_array()\n      ^");
    *((int64_t*)&_1196_x + _1195_t9) = _1195_t6._0;
    _1195_t13 = 1;
    _1195_t14 = 3;
    $bounds_check(_1195_t13, _1195_t14, "tests/integration/pattern/assign-array.orng:4:14:\n    (x[0], x[1], x[2]) = get_array()\n            ^");
    *((int64_t*)&_1196_x + _1195_t13) = _1195_t6._1;
    _1195_t17 = 2;
    _1195_t18 = 3;
    $bounds_check(_1195_t17, _1195_t18, "tests/integration/pattern/assign-array.orng:4:20:\n    (x[0], x[1], x[2]) = get_array()\n                  ^");
    *((int64_t*)&_1196_x + _1195_t17) = _1195_t6._2;
    _1195_t19 = 0;
    _1195_t20 = 3;
    _1195_t21 = 1;
    _1195_t22 = 3;
    $bounds_check(_1195_t19, _1195_t20, "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    $bounds_check(_1195_t21, _1195_t22, "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1195_t23 = $add_int64_t(*((int64_t*)&_1196_x + _1195_t19), *((int64_t*)&_1196_x + _1195_t21), "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1195_t24 = 2;
    _1195_t25 = 3;
    $bounds_check(_1195_t24, _1195_t25, "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    _1195_$retval = $add_int64_t(_1195_t23, *((int64_t*)&_1196_x + _1195_t24), "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _1195_$retval;
}

struct struct0 _1197_get_array(void){
    int64_t _1197_t1;
    int64_t _1197_t2;
    int64_t _1197_t3;
    struct struct0 _1197_$retval;
    _1197_t1 = 200;
    _1197_t2 = 3;
    _1197_t3 = 4;
    _1197_$retval = (struct struct0) {_1197_t1, _1197_t2, _1197_t3};
    return _1197_$retval;
}


int main(void) {
  printf("%ld",_1195_main());
  return 0;
}
