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
int64_t _1219_main(void);
struct struct0 _1221_get_array(void);


/* Function definitions */
int64_t _1219_main(void){
    int64_t _1219_t1;
    int64_t _1219_t2;
    int64_t _1219_t3;
    struct struct0 _1220_x;
    function1 _1219_t5;
    struct struct0 _1219_t6;
    int64_t _1219_t9;
    int64_t _1219_t10;
    int64_t _1219_t13;
    int64_t _1219_t14;
    int64_t _1219_t17;
    int64_t _1219_t18;
    int64_t _1219_t19;
    int64_t _1219_t20;
    int64_t _1219_t21;
    int64_t _1219_t22;
    int64_t _1219_t23;
    int64_t _1219_t24;
    int64_t _1219_t25;
    int64_t _1219_$retval;
    _1219_t1 = 0;
    _1219_t2 = 0;
    _1219_t3 = 0;
    _1220_x = (struct struct0) {_1219_t1, _1219_t2, _1219_t3};
    _1219_t5 = (function1) _1221_get_array;
    $lines[$line_idx++] = "tests/integration/pattern/assign-array.orng:4:36:\n    (x[0], x[1], x[2]) = get_array()\n                                  ^";
    _1219_t6 = _1219_t5();
    $line_idx--;
    _1219_t9 = 0;
    _1219_t10 = 3;
    $bounds_check(_1219_t9, _1219_t10, "tests/integration/pattern/assign-array.orng:4:8:\n    (x[0], x[1], x[2]) = get_array()\n      ^");
    *((int64_t*)&_1220_x + _1219_t9) = _1219_t6._0;
    _1219_t13 = 1;
    _1219_t14 = 3;
    $bounds_check(_1219_t13, _1219_t14, "tests/integration/pattern/assign-array.orng:4:14:\n    (x[0], x[1], x[2]) = get_array()\n            ^");
    *((int64_t*)&_1220_x + _1219_t13) = _1219_t6._1;
    _1219_t17 = 2;
    _1219_t18 = 3;
    $bounds_check(_1219_t17, _1219_t18, "tests/integration/pattern/assign-array.orng:4:20:\n    (x[0], x[1], x[2]) = get_array()\n                  ^");
    *((int64_t*)&_1220_x + _1219_t17) = _1219_t6._2;
    _1219_t19 = 0;
    _1219_t20 = 3;
    _1219_t21 = 1;
    _1219_t22 = 3;
    $bounds_check(_1219_t19, _1219_t20, "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    $bounds_check(_1219_t21, _1219_t22, "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1219_t23 = $add_int64_t(*((int64_t*)&_1220_x + _1219_t19), *((int64_t*)&_1220_x + _1219_t21), "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1219_t24 = 2;
    _1219_t25 = 3;
    $bounds_check(_1219_t24, _1219_t25, "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    _1219_$retval = $add_int64_t(_1219_t23, *((int64_t*)&_1220_x + _1219_t24), "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _1219_$retval;
}

struct struct0 _1221_get_array(void){
    int64_t _1221_t1;
    int64_t _1221_t2;
    int64_t _1221_t3;
    struct struct0 _1221_$retval;
    _1221_t1 = 200;
    _1221_t2 = 3;
    _1221_t3 = 4;
    _1221_$retval = (struct struct0) {_1221_t1, _1221_t2, _1221_t3};
    return _1221_$retval;
}


int main(void) {
  printf("%ld",_1219_main());
  return 0;
}
