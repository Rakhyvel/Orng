/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
} struct0;

typedef struct {
    struct0 _0;
    struct0 _1;
    struct0 _2;
} struct1;

/* Function forward definitions */
int64_t _1_main(void);
int64_t _3_f(struct1 _3_x);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t1;
    struct0 _1_t2;
    struct0 _1_t3;
    struct1 _2_x;
    int64_t _1_$retval;
    _1_t1 = (struct0) {.tag=0};
    _1_t2 = (struct0) {.tag=1};
    _1_t3 = (struct0) {.tag=2};
    _2_x = (struct1) {_1_t1, _1_t2, _1_t3};
    $lines[$line_idx++] = "tests/integration/arrays/array-sum.orng:6:7:\n    f(x)\n     ^";
    $line_idx--;
    _1_$retval = _3_f(_2_x);
    return _1_$retval;
}

int64_t _3_f(struct1 _3_x) {
    int64_t _3_t0;
    int64_t _3_$retval;
    if ((*((struct0*)&_3_x + 1)).tag == 1) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _3_t0 = 215;
    goto BB4;
BB5:
    _3_t0 = 3;
BB4:
    _3_$retval = _3_t0;
    return _3_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
