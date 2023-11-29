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
int64_t _822_main(void);
struct0 _825_get_array(void);

/* Function definitions */
int64_t _822_main(void) {
    int64_t _822_t1;
    int64_t _822_t2;
    int64_t _822_t3;
    struct0 _823_x;
    function1 _822_t4;
    struct0 _822_t5;
    int64_t _822_t7;
    int64_t _822_t9;
    int64_t _822_t11;
    int64_t _822_t12;
    int64_t _822_t13;
    int64_t _822_t14;
    int64_t _822_t15;
    int64_t _822_$retval;
    _822_t1 = 0;
    _822_t2 = 0;
    _822_t3 = 0;
    _823_x = (struct0) {_822_t1, _822_t2, _822_t3};
    _822_t4 = _825_get_array;
    $lines[$line_idx++] = "tests/integration/pattern/assign-array.orng:4:36:\n    (x[0], x[1], x[2]) = get_array()\n                                  ^";
    _822_t5 = _822_t4();
    $line_idx--;
    _822_t7 = 0;
    *((int64_t*)&_823_x + _822_t7) = _822_t5._0;
    _822_t9 = 1;
    *((int64_t*)&_823_x + _822_t9) = _822_t5._1;
    _822_t11 = 2;
    *((int64_t*)&_823_x + _822_t11) = _822_t5._2;
    _822_t12 = 0;
    _822_t13 = 1;
    _822_t14 = $add_int64_t(*((int64_t*)&_823_x + _822_t12), *((int64_t*)&_823_x + _822_t13), "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^");
    _822_t15 = 2;
    _822_$retval = $add_int64_t(_822_t14, *((int64_t*)&_823_x + _822_t15), "tests/integration/pattern/assign-array.orng:5:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _822_$retval;
}

struct0 _825_get_array(void) {
    int64_t _825_t1;
    int64_t _825_t2;
    int64_t _825_t3;
    struct0 _825_$retval;
    _825_t1 = 200;
    _825_t2 = 3;
    _825_t3 = 4;
    _825_$retval = (struct0) {_825_t1, _825_t2, _825_t3};
    return _825_$retval;
}

int main(void) {
  printf("%ld",_822_main());
  return 0;
}
