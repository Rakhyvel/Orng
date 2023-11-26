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
int64_t _654_main(void);
int64_t _656_add(struct1 _656_x);

/* Function definitions */
int64_t _654_main(void) {
    function0 _654_t0;
    int64_t _654_t3;
    int64_t _654_t4;
    int64_t _654_t5;
    struct1 _654_t2;
    int64_t _654_t1;
    int64_t _654_$retval;
    _654_t0 = _656_add;
    _654_t3 = 100;
    _654_t4 = 90;
    _654_t5 = 7;
    _654_t2 = (struct1) {_654_t3, _654_t4, _654_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _654_t1 = _654_t0(_654_t2);
    $line_idx--;
    _654_$retval = _654_t1;
    return _654_$retval;
}

int64_t _656_add(struct1 _656_x) {
    int64_t _656_t0;
    int64_t _656_t1;
    int64_t _656_t2;
    int64_t _656_t3;
    int64_t _656_$retval;
    _656_t0 = 0;
    _656_t1 = 1;
    _656_t2 = $add_int64_t(*((int64_t*)&_656_x + _656_t0), *((int64_t*)&_656_x + _656_t1), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _656_t3 = 2;
    _656_$retval = $add_int64_t(_656_t2, *((int64_t*)&_656_x + _656_t3), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _656_$retval;
}

int main(void) {
  printf("%ld",_654_main());
  return 0;
}
