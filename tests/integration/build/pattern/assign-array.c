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
int64_t _1162_main(void);
struct struct0 _1164_get_array(void);


/* Function definitions */
int64_t _1162_main(void){
    int64_t _1162_t1;
    int64_t _1162_t2;
    int64_t _1162_t3;
    struct struct0 _1163_x;
    function1 _1162_t5;
    struct struct0 _1162_t6;
    int64_t _1162_t9;
    int64_t _1162_t10;
    int64_t _1162_t13;
    int64_t _1162_t14;
    int64_t _1162_t17;
    int64_t _1162_t18;
    int64_t _1162_t19;
    int64_t _1162_t20;
    int64_t _1162_t21;
    int64_t _1162_t22;
    int64_t _1162_t23;
    int64_t _1162_t24;
    int64_t _1162_t25;
    int64_t _1162_$retval;
    _1162_t1 = 0;
    _1162_t2 = 0;
    _1162_t3 = 0;
    _1163_x = (struct struct0) {_1162_t1, _1162_t2, _1162_t3};
    _1162_t5 = (function1) _1164_get_array;
    $lines[$line_idx++] = "tests/integration/pattern/assign-array.orng:4:36:\n    (x[0], x[1], x[2]) = get_array()\n                                  ^";
    _1162_t6 = _1162_t5();
    $line_idx--;
    _1162_t9 = 0;
    _1162_t10 = 3;
    $bounds_check(_1162_t9, _1162_t10, "tests/integration/pattern/assign-array.orng:4:8:\n    (x[0], x[1], x[2]) = get_array()\n      ^");
    *((int64_t*)&_1163_x + _1162_t9) = _1162_t6._0;
    _1162_t13 = 1;
    _1162_t14 = 3;
    $bounds_check(_1162_t13, _1162_t14, "tests/integration/pattern/assign-array.orng:4:14:\n    (x[0], x[1], x[2]) = get_array()\n            ^");
    *((int64_t*)&_1163_x + _1162_t13) = _1162_t6._1;
    _1162_t17 = 2;
    _1162_t18 = 3;
    $bounds_check(_1162_t17, _1162_t18, "tests/integration/pattern/assign-array.orng:4:20:\n    (x[0], x[1], x[2]) = get_array()\n                  ^");
    *((int64_t*)&_1163_x + _1162_t17) = _1162_t6._2;
    _1162_t19 = 0;
    _1162_t20 = 3;
    _1162_t21 = 1;
    _1162_t22 = 3;
    $bounds_check(_1162_t19, _1162_t20, "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    $bounds_check(_1162_t21, _1162_t22, "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1162_t23 = $add_int64_t(*((int64_t*)&_1163_x + _1162_t19), *((int64_t*)&_1163_x + _1162_t21), "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1162_t24 = 2;
    _1162_t25 = 3;
    $bounds_check(_1162_t24, _1162_t25, "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    _1162_$retval = $add_int64_t(_1162_t23, *((int64_t*)&_1163_x + _1162_t24), "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _1162_$retval;
}

struct struct0 _1164_get_array(void){
    int64_t _1164_t1;
    int64_t _1164_t2;
    int64_t _1164_t3;
    struct struct0 _1164_$retval;
    _1164_t1 = 200;
    _1164_t2 = 3;
    _1164_t3 = 4;
    _1164_$retval = (struct struct0) {_1164_t1, _1164_t2, _1164_t3};
    return _1164_$retval;
}


int main(void) {
  printf("%ld",_1162_main());
  return 0;
}
