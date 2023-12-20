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
} struct0;

typedef struct0(*function1)(void);

/* Function forward definitions */
int64_t _1101_main(void);
struct0 _1103_get_array(void);

/* Function definitions */
int64_t _1101_main(void){
    int64_t _1101_t1;
    int64_t _1101_t2;
    int64_t _1101_t3;
    struct0 _1102_x;
    function1 _1101_t4;
    struct0 _1101_t5;
    int64_t _1101_t8;
    int64_t _1101_t9;
    int64_t _1101_t12;
    int64_t _1101_t13;
    int64_t _1101_t16;
    int64_t _1101_t17;
    int64_t _1101_t18;
    int64_t _1101_t19;
    int64_t _1101_t20;
    int64_t _1101_t21;
    int64_t _1101_t22;
    int64_t _1101_t23;
    int64_t _1101_t24;
    int64_t _1101_$retval;
    _1101_t1 = 0;
    _1101_t2 = 0;
    _1101_t3 = 0;
    _1102_x = (struct0) {_1101_t1, _1101_t2, _1101_t3};
    _1101_t4 = _1103_get_array;
    $lines[$line_idx++] = "tests/integration/pattern/assign-array.orng:4:36:\n    (x[0], x[1], x[2]) = get_array()\n                                  ^";
    _1101_t5 = _1101_t4();
    $line_idx--;
    _1101_t8 = 0;
    _1101_t9 = 3;
    $bounds_check(_1101_t8, _1101_t9, "tests/integration/pattern/assign-array.orng:4:8:\n    (x[0], x[1], x[2]) = get_array()\n      ^");
    *((int64_t*)&_1102_x + _1101_t8) = _1101_t5._0;
    _1101_t12 = 1;
    _1101_t13 = 3;
    $bounds_check(_1101_t12, _1101_t13, "tests/integration/pattern/assign-array.orng:4:14:\n    (x[0], x[1], x[2]) = get_array()\n            ^");
    *((int64_t*)&_1102_x + _1101_t12) = _1101_t5._1;
    _1101_t16 = 2;
    _1101_t17 = 3;
    $bounds_check(_1101_t16, _1101_t17, "tests/integration/pattern/assign-array.orng:4:20:\n    (x[0], x[1], x[2]) = get_array()\n                  ^");
    *((int64_t*)&_1102_x + _1101_t16) = _1101_t5._2;
    _1101_t18 = 0;
    _1101_t19 = 3;
    _1101_t20 = 1;
    _1101_t21 = 3;
    $bounds_check(_1101_t18, _1101_t19, "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    $bounds_check(_1101_t20, _1101_t21, "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1101_t22 = $add_int64_t(*((int64_t*)&_1102_x + _1101_t18), *((int64_t*)&_1102_x + _1101_t20), "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1101_t23 = 2;
    _1101_t24 = 3;
    $bounds_check(_1101_t23, _1101_t24, "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    _1101_$retval = $add_int64_t(_1101_t22, *((int64_t*)&_1102_x + _1101_t23), "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _1101_$retval;
}

struct0 _1103_get_array(void){
    int64_t _1103_t1;
    int64_t _1103_t2;
    int64_t _1103_t3;
    struct0 _1103_$retval;
    _1103_t1 = 200;
    _1103_t2 = 3;
    _1103_t3 = 4;
    _1103_$retval = (struct0) {_1103_t1, _1103_t2, _1103_t3};
    return _1103_$retval;
}

int main(void) {
  printf("%ld",_1101_main());
  return 0;
}
