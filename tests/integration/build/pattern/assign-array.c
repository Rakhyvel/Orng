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
int64_t _807_main(void);
struct0 _809_get_array(void);

/* Function definitions */
int64_t _807_main(void) {
    int64_t _807_t1;
    int64_t _807_t2;
    int64_t _807_t3;
    struct0 _808_x;
    function1 _807_t4;
    struct0 _807_t5;
    int64_t _807_t7;
    int64_t _807_t9;
    int64_t _807_t11;
    int64_t _807_t12;
    int64_t _807_t13;
    int64_t _807_t14;
    int64_t _807_t15;
    int64_t _807_$retval;
    _807_t1 = 0;
    _807_t2 = 0;
    _807_t3 = 0;
    _808_x = (struct0) {_807_t1, _807_t2, _807_t3};
    _807_t4 = _809_get_array;
    $lines[$line_idx++] = "tests/integration/pattern/assign-array.orng:4:36:\n    (x[0], x[1], x[2]) = get_array()\n                                  ^";
    _807_t5 = _807_t4();
    $line_idx--;
    _807_t7 = 0;
    *((int64_t*)&_808_x + _807_t7) = _807_t5._0;
    _807_t9 = 1;
    *((int64_t*)&_808_x + _807_t9) = _807_t5._1;
    _807_t11 = 2;
    *((int64_t*)&_808_x + _807_t11) = _807_t5._2;
    _807_t12 = 0;
    _807_t13 = 1;
    _807_t14 = $add_int64_t(*((int64_t*)&_808_x + _807_t12), *((int64_t*)&_808_x + _807_t13), "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _807_t15 = 2;
    _807_$retval = $add_int64_t(_807_t14, *((int64_t*)&_808_x + _807_t15), "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _807_$retval;
}

struct0 _809_get_array(void) {
    int64_t _809_t1;
    int64_t _809_t2;
    int64_t _809_t3;
    struct0 _809_$retval;
    _809_t1 = 200;
    _809_t2 = 3;
    _809_t3 = 4;
    _809_$retval = (struct0) {_809_t1, _809_t2, _809_t3};
    return _809_$retval;
}

int main(void) {
  printf("%ld",_807_main());
  return 0;
}
