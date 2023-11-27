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
int64_t _748_main(void);
struct0 _750_get_array(void);

/* Function definitions */
int64_t _748_main(void) {
    int64_t _748_t1;
    int64_t _748_t2;
    int64_t _748_t3;
    struct0 _749_x;
    function1 _748_t4;
    struct0 _748_t5;
    int64_t _748_t7;
    int64_t _748_t9;
    int64_t _748_t11;
    int64_t _748_t12;
    int64_t _748_t13;
    int64_t _748_t14;
    int64_t _748_t15;
    int64_t _748_$retval;
    _748_t1 = 0;
    _748_t2 = 0;
    _748_t3 = 0;
    _749_x = (struct0) {_748_t1, _748_t2, _748_t3};
    _748_t4 = _750_get_array;
    $lines[$line_idx++] = "tests/integration/pattern/assign-array.orng:4:36:\n    (x[0], x[1], x[2]) = get_array()\n                                  ^";
    _748_t5 = _748_t4();
    $line_idx--;
    _748_t7 = 0;
    *((int64_t*)&_749_x + _748_t7) = _748_t5._0;
    _748_t9 = 1;
    *((int64_t*)&_749_x + _748_t9) = _748_t5._1;
    _748_t11 = 2;
    *((int64_t*)&_749_x + _748_t11) = _748_t5._2;
    _748_t12 = 0;
    _748_t13 = 1;
    _748_t14 = $add_int64_t(*((int64_t*)&_749_x + _748_t12), *((int64_t*)&_749_x + _748_t13), "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _748_t15 = 2;
    _748_$retval = $add_int64_t(_748_t14, *((int64_t*)&_749_x + _748_t15), "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _748_$retval;
}

struct0 _750_get_array(void) {
    int64_t _750_t1;
    int64_t _750_t2;
    int64_t _750_t3;
    struct0 _750_$retval;
    _750_t1 = 200;
    _750_t2 = 3;
    _750_t3 = 4;
    _750_$retval = (struct0) {_750_t1, _750_t2, _750_t3};
    return _750_$retval;
}

int main(void) {
  printf("%ld",_748_main());
  return 0;
}
