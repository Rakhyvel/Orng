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
int64_t _938_main(void);
int64_t _940_add(struct1 _940_x);

/* Function definitions */
int64_t _938_main(void) {
    function0 _938_t0;
    int64_t _938_t3;
    int64_t _938_t4;
    int64_t _938_t5;
    struct1 _938_t2;
    int64_t _938_t1;
    int64_t _938_$retval;
    _938_t0 = _940_add;
    _938_t3 = 100;
    _938_t4 = 90;
    _938_t5 = 7;
    _938_t2 = (struct1) {_938_t3, _938_t4, _938_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _938_t1 = _938_t0(_938_t2);
    $line_idx--;
    _938_$retval = _938_t1;
    return _938_$retval;
}

int64_t _940_add(struct1 _940_x) {
    int64_t _940_t0;
    int64_t _940_t1;
    int64_t _940_t2;
    int64_t _940_t3;
    int64_t _940_$retval;
    _940_t0 = 0;
    _940_t1 = 1;
    _940_t2 = $add_int64_t(*((int64_t*)&_940_x + _940_t0), *((int64_t*)&_940_x + _940_t1), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _940_t3 = 2;
    _940_$retval = $add_int64_t(_940_t2, *((int64_t*)&_940_x + _940_t3), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _940_$retval;
}

int main(void) {
  printf("%ld",_938_main());
  return 0;
}
