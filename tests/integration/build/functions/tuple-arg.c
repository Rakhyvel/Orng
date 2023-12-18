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
int64_t _1110_main(void);
int64_t _1112_add(struct1 _1112_x);

/* Function definitions */
int64_t _1110_main(void){
    function0 _1110_t0;
    int64_t _1110_t3;
    int64_t _1110_t4;
    int64_t _1110_t5;
    struct1 _1110_t2;
    int64_t _1110_t1;
    int64_t _1110_$retval;
    _1110_t0 = _1112_add;
    _1110_t3 = 100;
    _1110_t4 = 90;
    _1110_t5 = 7;
    _1110_t2 = (struct1) {_1110_t3, _1110_t4, _1110_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _1110_t1 = _1110_t0(_1110_t2);
    $line_idx--;
    _1110_$retval = _1110_t1;
    return _1110_$retval;
}

int64_t _1112_add(struct1 _1112_x){
    int64_t _1112_t0;
    int64_t _1112_t1;
    int64_t _1112_t2;
    int64_t _1112_t3;
    int64_t _1112_t4;
    int64_t _1112_t5;
    int64_t _1112_t6;
    int64_t _1112_$retval;
    _1112_t0 = 0;
    _1112_t1 = 3;
    _1112_t2 = 1;
    _1112_t3 = 3;
    $bounds_check(_1112_t0, _1112_t1, "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    $bounds_check(_1112_t2, _1112_t3, "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1112_t4 = $add_int64_t(*((int64_t*)&_1112_x + _1112_t0), *((int64_t*)&_1112_x + _1112_t2), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1112_t5 = 2;
    _1112_t6 = 3;
    $bounds_check(_1112_t5, _1112_t6, "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    _1112_$retval = $add_int64_t(_1112_t4, *((int64_t*)&_1112_x + _1112_t5), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _1112_$retval;
}

int main(void) {
  printf("%ld",_1110_main());
  return 0;
}
