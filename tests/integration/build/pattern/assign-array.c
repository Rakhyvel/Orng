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
int64_t _1018_main(void);
struct0 _1024_get_array(void);

/* Function definitions */
int64_t _1018_main(void) {
    int64_t _1018_t1;
    int64_t _1018_t2;
    int64_t _1018_t3;
    struct0 _1019_x;
    function1 _1018_t4;
    struct0 _1018_t5;
    int64_t _1018_t7;
    int64_t _1018_t9;
    int64_t _1018_t11;
    int64_t _1018_t12;
    int64_t _1018_t13;
    int64_t _1018_t14;
    int64_t _1018_t15;
    int64_t _1018_$retval;
    _1018_t1 = 0;
    _1018_t2 = 0;
    _1018_t3 = 0;
    _1019_x = (struct0) {_1018_t1, _1018_t2, _1018_t3};
    _1018_t4 = _1024_get_array;
    $lines[$line_idx++] = "tests/integration/pattern/assign-array.orng:4:36:\n    (x[0], x[1], x[2]) = get_array()\n                                  ^";
    _1018_t5 = _1018_t4();
    $line_idx--;
    _1018_t7 = 0;
    *((int64_t*)&_1019_x + _1018_t7) = _1018_t5._0;
    _1018_t9 = 1;
    *((int64_t*)&_1019_x + _1018_t9) = _1018_t5._1;
    _1018_t11 = 2;
    *((int64_t*)&_1019_x + _1018_t11) = _1018_t5._2;
    _1018_t12 = 0;
    _1018_t13 = 1;
    _1018_t14 = $add_int64_t(*((int64_t*)&_1019_x + _1018_t12), *((int64_t*)&_1019_x + _1018_t13), "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1018_t15 = 2;
    _1018_$retval = $add_int64_t(_1018_t14, *((int64_t*)&_1019_x + _1018_t15), "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _1018_$retval;
}

struct0 _1024_get_array(void) {
    int64_t _1024_t1;
    int64_t _1024_t2;
    int64_t _1024_t3;
    struct0 _1024_$retval;
    _1024_t1 = 200;
    _1024_t2 = 3;
    _1024_t3 = 4;
    _1024_$retval = (struct0) {_1024_t1, _1024_t2, _1024_t3};
    return _1024_$retval;
}

int main(void) {
  printf("%ld",_1018_main());
  return 0;
}
