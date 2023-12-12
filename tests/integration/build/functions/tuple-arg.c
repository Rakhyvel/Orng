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
int64_t _749_main(void);
int64_t _751_add(struct1 _751_x);

/* Function definitions */
int64_t _749_main(void) {
    function0 _749_t0;
    int64_t _749_t3;
    int64_t _749_t4;
    int64_t _749_t5;
    struct1 _749_t2;
    int64_t _749_t1;
    int64_t _749_$retval;
    _749_t0 = _751_add;
    _749_t3 = 100;
    _749_t4 = 90;
    _749_t5 = 7;
    _749_t2 = (struct1) {_749_t3, _749_t4, _749_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _749_t1 = _749_t0(_749_t2);
    $line_idx--;
    _749_$retval = _749_t1;
    return _749_$retval;
}

int64_t _751_add(struct1 _751_x) {
    int64_t _751_t0;
    int64_t _751_t1;
    int64_t _751_t2;
    int64_t _751_t3;
    int64_t _751_$retval;
    _751_t0 = 0;
    _751_t1 = 1;
    _751_t2 = $add_int64_t(*((int64_t*)&_751_x + _751_t0), *((int64_t*)&_751_x + _751_t1), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _751_t3 = 2;
    _751_$retval = $add_int64_t(_751_t2, *((int64_t*)&_751_x + _751_t3), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _751_$retval;
}

int main(void) {
  printf("%ld",_749_main());
  return 0;
}
