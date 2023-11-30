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
int64_t _905_main(void);
int64_t _907_add(struct1 _907_x);

/* Function definitions */
int64_t _905_main(void) {
    function0 _905_t0;
    int64_t _905_t3;
    int64_t _905_t4;
    int64_t _905_t5;
    struct1 _905_t2;
    int64_t _905_t1;
    int64_t _905_$retval;
    _905_t0 = _907_add;
    _905_t3 = 100;
    _905_t4 = 90;
    _905_t5 = 7;
    _905_t2 = (struct1) {_905_t3, _905_t4, _905_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _905_t1 = _905_t0(_905_t2);
    $line_idx--;
    _905_$retval = _905_t1;
    return _905_$retval;
}

int64_t _907_add(struct1 _907_x) {
    int64_t _907_t0;
    int64_t _907_t1;
    int64_t _907_t2;
    int64_t _907_t3;
    int64_t _907_$retval;
    _907_t0 = 0;
    _907_t1 = 1;
    _907_t2 = $add_int64_t(*((int64_t*)&_907_x + _907_t0), *((int64_t*)&_907_x + _907_t1), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _907_t3 = 2;
    _907_$retval = $add_int64_t(_907_t2, *((int64_t*)&_907_x + _907_t3), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _907_$retval;
}

int main(void) {
  printf("%ld",_905_main());
  return 0;
}
