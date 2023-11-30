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
int64_t _928_main(void);
int64_t _930_add(struct1 _930_x);

/* Function definitions */
int64_t _928_main(void) {
    function0 _928_t0;
    int64_t _928_t3;
    int64_t _928_t4;
    int64_t _928_t5;
    struct1 _928_t2;
    int64_t _928_t1;
    int64_t _928_$retval;
    _928_t0 = _930_add;
    _928_t3 = 100;
    _928_t4 = 90;
    _928_t5 = 7;
    _928_t2 = (struct1) {_928_t3, _928_t4, _928_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _928_t1 = _928_t0(_928_t2);
    $line_idx--;
    _928_$retval = _928_t1;
    return _928_$retval;
}

int64_t _930_add(struct1 _930_x) {
    int64_t _930_t0;
    int64_t _930_t1;
    int64_t _930_t2;
    int64_t _930_t3;
    int64_t _930_$retval;
    _930_t0 = 0;
    _930_t1 = 1;
    _930_t2 = $add_int64_t(*((int64_t*)&_930_x + _930_t0), *((int64_t*)&_930_x + _930_t1), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _930_t3 = 2;
    _930_$retval = $add_int64_t(_930_t2, *((int64_t*)&_930_x + _930_t3), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _930_$retval;
}

int main(void) {
  printf("%ld",_928_main());
  return 0;
}
