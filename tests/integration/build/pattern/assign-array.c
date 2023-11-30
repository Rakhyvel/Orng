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
int64_t _1003_main(void);
struct0 _1007_get_array(void);

/* Function definitions */
int64_t _1003_main(void) {
    int64_t _1003_t1;
    int64_t _1003_t2;
    int64_t _1003_t3;
    struct0 _1004_x;
    function1 _1003_t4;
    struct0 _1003_t5;
    int64_t _1003_t7;
    int64_t _1003_t9;
    int64_t _1003_t11;
    int64_t _1003_t12;
    int64_t _1003_t13;
    int64_t _1003_t14;
    int64_t _1003_t15;
    int64_t _1003_$retval;
    _1003_t1 = 0;
    _1003_t2 = 0;
    _1003_t3 = 0;
    _1004_x = (struct0) {_1003_t1, _1003_t2, _1003_t3};
    _1003_t4 = _1007_get_array;
    $lines[$line_idx++] = "tests/integration/pattern/assign-array.orng:4:36:\n    (x[0], x[1], x[2]) = get_array()\n                                  ^";
    _1003_t5 = _1003_t4();
    $line_idx--;
    _1003_t7 = 0;
    *((int64_t*)&_1004_x + _1003_t7) = _1003_t5._0;
    _1003_t9 = 1;
    *((int64_t*)&_1004_x + _1003_t9) = _1003_t5._1;
    _1003_t11 = 2;
    *((int64_t*)&_1004_x + _1003_t11) = _1003_t5._2;
    _1003_t12 = 0;
    _1003_t13 = 1;
    _1003_t14 = $add_int64_t(*((int64_t*)&_1004_x + _1003_t12), *((int64_t*)&_1004_x + _1003_t13), "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1003_t15 = 2;
    _1003_$retval = $add_int64_t(_1003_t14, *((int64_t*)&_1004_x + _1003_t15), "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _1003_$retval;
}

struct0 _1007_get_array(void) {
    int64_t _1007_t1;
    int64_t _1007_t2;
    int64_t _1007_t3;
    struct0 _1007_$retval;
    _1007_t1 = 200;
    _1007_t2 = 3;
    _1007_t3 = 4;
    _1007_$retval = (struct0) {_1007_t1, _1007_t2, _1007_t3};
    return _1007_$retval;
}

int main(void) {
  printf("%ld",_1003_main());
  return 0;
}
