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
int64_t _2_main(void);
struct0 _4_get_array(void);

/* Function definitions */
int64_t _2_main(void) {
    int64_t _2_t1;
    int64_t _2_t2;
    int64_t _2_t3;
    struct0 _3_x;
    function1 _2_t4;
    struct0 _2_t5;
    int64_t _2_t7;
    int64_t _2_t9;
    int64_t _2_t11;
    int64_t _2_t12;
    int64_t _2_t13;
    int64_t _2_t14;
    int64_t _2_t15;
    int64_t _2_$retval;
    _2_t1 = 0;
    _2_t2 = 0;
    _2_t3 = 0;
    _3_x = (struct0) {_2_t1, _2_t2, _2_t3};
    _2_t4 = _4_get_array;
    $lines[$line_idx++] = "tests/integration/pattern/assign-array.orng:4:36:\n    (x[0], x[1], x[2]) = get_array()\n                                  ^";
    _2_t5 = _2_t4();
    $line_idx--;
    _2_t7 = 0;
    *((int64_t*)&_3_x + _2_t7) = _2_t5._0;
    _2_t9 = 1;
    *((int64_t*)&_3_x + _2_t9) = _2_t5._1;
    _2_t11 = 2;
    *((int64_t*)&_3_x + _2_t11) = _2_t5._2;
    _2_t12 = 0;
    _2_t13 = 1;
    _2_t14 = $add_int64_t(*((int64_t*)&_3_x + _2_t12), *((int64_t*)&_3_x + _2_t13), "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _2_t15 = 2;
    _2_$retval = $add_int64_t(_2_t14, *((int64_t*)&_3_x + _2_t15), "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _2_$retval;
}

struct0 _4_get_array(void) {
    int64_t _4_t1;
    int64_t _4_t2;
    int64_t _4_t3;
    struct0 _4_$retval;
    _4_t1 = 200;
    _4_t2 = 3;
    _4_t3 = 4;
    _4_$retval = (struct0) {_4_t1, _4_t2, _4_t3};
    return _4_$retval;
}

int main(void) {
  printf("%ld",_2_main());
  return 0;
}
