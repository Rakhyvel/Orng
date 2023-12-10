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
int64_t _741_main(void);
int64_t _743_add(struct1 _743_x);

/* Function definitions */
int64_t _741_main(void) {
    function0 _741_t0;
    int64_t _741_t3;
    int64_t _741_t4;
    int64_t _741_t5;
    struct1 _741_t2;
    int64_t _741_t1;
    int64_t _741_$retval;
    _741_t0 = _743_add;
    _741_t3 = 100;
    _741_t4 = 90;
    _741_t5 = 7;
    _741_t2 = (struct1) {_741_t3, _741_t4, _741_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _741_t1 = _741_t0(_741_t2);
    $line_idx--;
    _741_$retval = _741_t1;
    return _741_$retval;
}

int64_t _743_add(struct1 _743_x) {
    int64_t _743_t0;
    int64_t _743_t1;
    int64_t _743_t2;
    int64_t _743_t3;
    int64_t _743_$retval;
    _743_t0 = 0;
    _743_t1 = 1;
    _743_t2 = $add_int64_t(*((int64_t*)&_743_x + _743_t0), *((int64_t*)&_743_x + _743_t1), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _743_t3 = 2;
    _743_$retval = $add_int64_t(_743_t2, *((int64_t*)&_743_x + _743_t3), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _743_$retval;
}

int main(void) {
  printf("%ld",_741_main());
  return 0;
}
