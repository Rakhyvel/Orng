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
} struct1;

typedef int64_t(*function0)(struct1);

/* Function forward definitions */
int64_t _685_main(void);
int64_t _687_add(struct1 _687_x);

/* Function definitions */
int64_t _685_main(void) {
    function0 _685_t0;
    int64_t _685_t3;
    int64_t _685_t4;
    int64_t _685_t5;
    struct1 _685_t2;
    int64_t _685_t1;
    int64_t _685_$retval;
    _685_t0 = _687_add;
    _685_t3 = 100;
    _685_t4 = 90;
    _685_t5 = 7;
    _685_t2 = (struct1) {_685_t3, _685_t4, _685_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _685_t1 = _685_t0(_685_t2);
    $line_idx--;
    _685_$retval = _685_t1;
    return _685_$retval;
}

int64_t _687_add(struct1 _687_x) {
    int64_t _687_t0;
    int64_t _687_t1;
    int64_t _687_t2;
    int64_t _687_t3;
    int64_t _687_$retval;
    _687_t0 = 0;
    _687_t1 = 1;
    _687_t2 = $add_int64_t(*((int64_t*)&_687_x + _687_t0), *((int64_t*)&_687_x + _687_t1), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _687_t3 = 2;
    _687_$retval = $add_int64_t(_687_t2, *((int64_t*)&_687_x + _687_t3), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _687_$retval;
}

int main(void) {
  printf("%ld",_685_main());
  return 0;
}
