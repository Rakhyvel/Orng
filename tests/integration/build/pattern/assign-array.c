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
int64_t _815_main(void);
struct0 _817_get_array(void);

/* Function definitions */
int64_t _815_main(void) {
    int64_t _815_t1;
    int64_t _815_t2;
    int64_t _815_t3;
    struct0 _816_x;
    function1 _815_t4;
    struct0 _815_t5;
    int64_t _815_t7;
    int64_t _815_t9;
    int64_t _815_t11;
    int64_t _815_t12;
    int64_t _815_t13;
    int64_t _815_t14;
    int64_t _815_t15;
    int64_t _815_$retval;
    _815_t1 = 0;
    _815_t2 = 0;
    _815_t3 = 0;
    _816_x = (struct0) {_815_t1, _815_t2, _815_t3};
    _815_t4 = _817_get_array;
    $lines[$line_idx++] = "tests/integration/pattern/assign-array.orng:4:36:\n    (x[0], x[1], x[2]) = get_array()\n                                  ^";
    _815_t5 = _815_t4();
    $line_idx--;
    _815_t7 = 0;
    *((int64_t*)&_816_x + _815_t7) = _815_t5._0;
    _815_t9 = 1;
    *((int64_t*)&_816_x + _815_t9) = _815_t5._1;
    _815_t11 = 2;
    *((int64_t*)&_816_x + _815_t11) = _815_t5._2;
    _815_t12 = 0;
    _815_t13 = 1;
    _815_t14 = $add_int64_t(*((int64_t*)&_816_x + _815_t12), *((int64_t*)&_816_x + _815_t13), "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _815_t15 = 2;
    _815_$retval = $add_int64_t(_815_t14, *((int64_t*)&_816_x + _815_t15), "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _815_$retval;
}

struct0 _817_get_array(void) {
    int64_t _817_t1;
    int64_t _817_t2;
    int64_t _817_t3;
    struct0 _817_$retval;
    _817_t1 = 200;
    _817_t2 = 3;
    _817_t3 = 4;
    _817_$retval = (struct0) {_817_t1, _817_t2, _817_t3};
    return _817_$retval;
}

int main(void) {
  printf("%ld",_815_main());
  return 0;
}
