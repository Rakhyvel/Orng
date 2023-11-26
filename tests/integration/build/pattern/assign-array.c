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
int64_t _717_main(void);
struct0 _719_get_array(void);

/* Function definitions */
int64_t _717_main(void) {
    int64_t _717_t1;
    int64_t _717_t2;
    int64_t _717_t3;
    struct0 _718_x;
    function1 _717_t4;
    struct0 _717_t5;
    int64_t _717_t7;
    int64_t _717_t9;
    int64_t _717_t11;
    int64_t _717_t12;
    int64_t _717_t13;
    int64_t _717_t14;
    int64_t _717_t15;
    int64_t _717_$retval;
    _717_t1 = 0;
    _717_t2 = 0;
    _717_t3 = 0;
    _718_x = (struct0) {_717_t1, _717_t2, _717_t3};
    _717_t4 = _719_get_array;
    $lines[$line_idx++] = "tests/integration/pattern/assign-array.orng:4:36:\n    (x[0], x[1], x[2]) = get_array()\n                                  ^";
    _717_t5 = _717_t4();
    $line_idx--;
    _717_t7 = 0;
    *((int64_t*)&_718_x + _717_t7) = _717_t5._0;
    _717_t9 = 1;
    *((int64_t*)&_718_x + _717_t9) = _717_t5._1;
    _717_t11 = 2;
    *((int64_t*)&_718_x + _717_t11) = _717_t5._2;
    _717_t12 = 0;
    _717_t13 = 1;
    _717_t14 = $add_int64_t(*((int64_t*)&_718_x + _717_t12), *((int64_t*)&_718_x + _717_t13), "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _717_t15 = 2;
    _717_$retval = $add_int64_t(_717_t14, *((int64_t*)&_718_x + _717_t15), "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _717_$retval;
}

struct0 _719_get_array(void) {
    int64_t _719_t1;
    int64_t _719_t2;
    int64_t _719_t3;
    struct0 _719_$retval;
    _719_t1 = 200;
    _719_t2 = 3;
    _719_t3 = 4;
    _719_$retval = (struct0) {_719_t1, _719_t2, _719_t3};
    return _719_$retval;
}

int main(void) {
  printf("%ld",_717_main());
  return 0;
}
