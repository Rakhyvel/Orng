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
int64_t _783_main(void);
struct0 _785_get_array(void);

/* Function definitions */
int64_t _783_main(void) {
    int64_t _783_t1;
    int64_t _783_t2;
    int64_t _783_t3;
    struct0 _784_x;
    function1 _783_t4;
    struct0 _783_t5;
    int64_t _783_t7;
    int64_t _783_t9;
    int64_t _783_t11;
    int64_t _783_t12;
    int64_t _783_t13;
    int64_t _783_t14;
    int64_t _783_t15;
    int64_t _783_$retval;
    _783_t1 = 0;
    _783_t2 = 0;
    _783_t3 = 0;
    _784_x = (struct0) {_783_t1, _783_t2, _783_t3};
    _783_t4 = _785_get_array;
    $lines[$line_idx++] = "tests/integration/pattern/assign-array.orng:4:36:\n    (x[0], x[1], x[2]) = get_array()\n                                  ^";
    _783_t5 = _783_t4();
    $line_idx--;
    _783_t7 = 0;
    *((int64_t*)&_784_x + _783_t7) = _783_t5._0;
    _783_t9 = 1;
    *((int64_t*)&_784_x + _783_t9) = _783_t5._1;
    _783_t11 = 2;
    *((int64_t*)&_784_x + _783_t11) = _783_t5._2;
    _783_t12 = 0;
    _783_t13 = 1;
    _783_t14 = $add_int64_t(*((int64_t*)&_784_x + _783_t12), *((int64_t*)&_784_x + _783_t13), "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _783_t15 = 2;
    _783_$retval = $add_int64_t(_783_t14, *((int64_t*)&_784_x + _783_t15), "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _783_$retval;
}

struct0 _785_get_array(void) {
    int64_t _785_t1;
    int64_t _785_t2;
    int64_t _785_t3;
    struct0 _785_$retval;
    _785_t1 = 200;
    _785_t2 = 3;
    _785_t3 = 4;
    _785_$retval = (struct0) {_785_t1, _785_t2, _785_t3};
    return _785_$retval;
}

int main(void) {
  printf("%ld",_783_main());
  return 0;
}
