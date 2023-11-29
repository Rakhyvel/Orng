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
int64_t _70_main(void);
int64_t _72_add(struct1 _72_x);

/* Function definitions */
int64_t _70_main(void) {
    function0 _70_t0;
    int64_t _70_t3;
    int64_t _70_t4;
    int64_t _70_t5;
    struct1 _70_t2;
    int64_t _70_t1;
    int64_t _70_$retval;
    _70_t0 = _72_add;
    _70_t3 = 100;
    _70_t4 = 90;
    _70_t5 = 7;
    _70_t2 = (struct1) {_70_t3, _70_t4, _70_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _70_t1 = _70_t0(_70_t2);
    $line_idx--;
    _70_$retval = _70_t1;
    return _70_$retval;
}

int64_t _72_add(struct1 _72_x) {
    int64_t _72_t0;
    int64_t _72_t1;
    int64_t _72_t2;
    int64_t _72_t3;
    int64_t _72_$retval;
    _72_t0 = 0;
    _72_t1 = 1;
    _72_t2 = $add_int64_t(*((int64_t*)&_72_x + _72_t0), *((int64_t*)&_72_x + _72_t1), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _72_t3 = 2;
    _72_$retval = $add_int64_t(_72_t2, *((int64_t*)&_72_x + _72_t3), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _72_$retval;
}

int main(void) {
  printf("%ld",_70_main());
  return 0;
}
