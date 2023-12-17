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
int64_t _1102_main(void);
int64_t _1104_add(struct1 _1104_x);

/* Function definitions */
int64_t _1102_main(void){
    function0 _1102_t0;
    int64_t _1102_t3;
    int64_t _1102_t4;
    int64_t _1102_t5;
    struct1 _1102_t2;
    int64_t _1102_t1;
    int64_t _1102_$retval;
    _1102_t0 = _1104_add;
    _1102_t3 = 100;
    _1102_t4 = 90;
    _1102_t5 = 7;
    _1102_t2 = (struct1) {_1102_t3, _1102_t4, _1102_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _1102_t1 = _1102_t0(_1102_t2);
    $line_idx--;
    _1102_$retval = _1102_t1;
    return _1102_$retval;
}

int64_t _1104_add(struct1 _1104_x){
    int64_t _1104_t0;
    int64_t _1104_t1;
    int64_t _1104_t2;
    int64_t _1104_t3;
    int64_t _1104_t4;
    int64_t _1104_t5;
    int64_t _1104_t6;
    int64_t _1104_$retval;
    _1104_t0 = 0;
    _1104_t1 = 3;
    _1104_t2 = 1;
    _1104_t3 = 3;
    $bounds_check(_1104_t0, _1104_t1, "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    $bounds_check(_1104_t2, _1104_t3, "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1104_t4 = $add_int64_t(*((int64_t*)&_1104_x + _1104_t0), *((int64_t*)&_1104_x + _1104_t2), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1104_t5 = 2;
    _1104_t6 = 3;
    $bounds_check(_1104_t5, _1104_t6, "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    _1104_$retval = $add_int64_t(_1104_t4, *((int64_t*)&_1104_x + _1104_t5), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _1104_$retval;
}

int main(void) {
  printf("%ld",_1102_main());
  return 0;
}
