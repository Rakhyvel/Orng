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
} struct0;

/* Function forward definitions */
int64_t _1_main(void);
int64_t _3_add(struct0 _3_x);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t1;
    int64_t _1_t0;
    int64_t _1_$retval;
    _1_t1 = (struct0) {100, 90, 7};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _1_t0 = _3_add(_1_t1);
    $line_idx--;
    _1_$retval = _1_t0;
    return _1_$retval;
}

int64_t _3_add(struct0 _3_x) {
    int64_t _3_$retval;
    _3_$retval = $add_int64_t($add_int64_t(*(int64_t*)&_3_x, *((int64_t*)&_3_x + 1), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^"), *((int64_t*)&_3_x + 2), "tests/integration/functions/tuple-arg.orng:6:3:\nfn add(x: [3]Int) -> Int {\n ^");
    return _3_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
