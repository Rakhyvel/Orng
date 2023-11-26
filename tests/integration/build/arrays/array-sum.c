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

typedef int64_t(*function2)(struct1);

typedef struct {
    struct0 _0;
    struct0 _1;
    struct0 _2;
} struct3;

/* Function forward definitions */
int64_t _50_main(void);
int64_t _52_f(struct1 _52_x);

/* Function definitions */
int64_t _50_main(void) {
    struct0 _50_t1;
    struct0 _50_t2;
    struct0 _50_t3;
    struct1 _51_x;
    function2 _50_t4;
    int64_t _50_t5;
    int64_t _50_$retval;
    _50_t1 = (struct0) {.tag=0};
    _50_t2 = (struct0) {.tag=1};
    _50_t3 = (struct0) {.tag=2};
    _51_x = (struct1) {_50_t1, _50_t2, _50_t3};
    _50_t4 = _52_f;
    $lines[$line_idx++] = "tests/integration/arrays/array-sum.orng:6:7:\n    f(x)\n     ^";
    _50_t5 = _50_t4(_51_x);
    $line_idx--;
    _50_$retval = _50_t5;
    return _50_$retval;
}

int64_t _52_f(struct1 _52_x) {
    int64_t _52_t1;
    uint64_t _52_t5;
    uint64_t _52_t6;
    uint8_t _52_t4;
    uint8_t _52_t3;
    int64_t _52_t0;
    int64_t _52_$retval;
    _52_t1 = 1;
    _52_t5 = (*((struct0*)&_52_x + _52_t1)).tag;
    _52_t6 = 1;
    _52_t4 = _52_t5 == _52_t6;
    if (_52_t4) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _52_t3 = 1;
    goto BB2;
BB9:
    _52_t3 = 0;
BB2:
    if (_52_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _52_t0 = 215;
    goto BB6;
BB7:
    _52_t0 = 3;
BB6:
    _52_$retval = _52_t0;
    return _52_$retval;
}

int main(void) {
  printf("%ld",_50_main());
  return 0;
}
