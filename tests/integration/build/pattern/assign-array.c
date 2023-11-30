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
int64_t _980_main(void);
struct0 _984_get_array(void);

/* Function definitions */
int64_t _980_main(void) {
    int64_t _980_t1;
    int64_t _980_t2;
    int64_t _980_t3;
    struct0 _981_x;
    function1 _980_t4;
    struct0 _980_t5;
    int64_t _980_t7;
    int64_t _980_t9;
    int64_t _980_t11;
    int64_t _980_t12;
    int64_t _980_t13;
    int64_t _980_t14;
    int64_t _980_t15;
    int64_t _980_$retval;
    _980_t1 = 0;
    _980_t2 = 0;
    _980_t3 = 0;
    _981_x = (struct0) {_980_t1, _980_t2, _980_t3};
    _980_t4 = _984_get_array;
    $lines[$line_idx++] = "tests/integration/pattern/assign-array.orng:4:36:\n    (x[0], x[1], x[2]) = get_array()\n                                  ^";
    _980_t5 = _980_t4();
    $line_idx--;
    _980_t7 = 0;
    *((int64_t*)&_981_x + _980_t7) = _980_t5._0;
    _980_t9 = 1;
    *((int64_t*)&_981_x + _980_t9) = _980_t5._1;
    _980_t11 = 2;
    *((int64_t*)&_981_x + _980_t11) = _980_t5._2;
    _980_t12 = 0;
    _980_t13 = 1;
    _980_t14 = $add_int64_t(*((int64_t*)&_981_x + _980_t12), *((int64_t*)&_981_x + _980_t13), "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _980_t15 = 2;
    _980_$retval = $add_int64_t(_980_t14, *((int64_t*)&_981_x + _980_t15), "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _980_$retval;
}

struct0 _984_get_array(void) {
    int64_t _984_t1;
    int64_t _984_t2;
    int64_t _984_t3;
    struct0 _984_$retval;
    _984_t1 = 200;
    _984_t2 = 3;
    _984_t3 = 4;
    _984_$retval = (struct0) {_984_t1, _984_t2, _984_t3};
    return _984_$retval;
}

int main(void) {
  printf("%ld",_980_main());
  return 0;
}
