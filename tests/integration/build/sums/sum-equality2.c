/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _1;
    };
} struct1;

typedef struct1(*function0)(void);

/* Function forward definitions */
int64_t _40_main(void);
struct1 _45_f(void);

/* Function definitions */
int64_t _40_main(void) {
    function0 _40_t1;
    struct1 _40_t2;
    function0 _40_t3;
    struct1 _40_t4;
    uint64_t _40_t7;
    uint64_t _40_t8;
    uint8_t _40_t6;
    uint8_t _40_t5;
    int64_t _40_t0;
    int64_t _40_$retval;
    _40_t1 = _45_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _40_t2 = _40_t1();
    $line_idx--;
    _40_t3 = _45_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _40_t4 = _40_t3();
    $line_idx--;
    _40_t7 = _40_t2.tag;
    _40_t8 = _40_t4.tag;
    _40_t6 = _40_t7 == _40_t8;
    if (_40_t6) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _40_t5 = 1;
    goto BB2;
BB9:
    _40_t5 = 0;
    goto BB2;
BB2:
    if (_40_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _40_t0 = 212;
    goto BB6;
BB7:
    _40_t0 = -1;
    goto BB6;
BB6:
    _40_$retval = _40_t0;
    return _40_$retval;
}

struct1 _45_f(void) {
    struct1 _45_$retval;
    _45_$retval = (struct1) {.tag=0};
    return _45_$retval;
}

int main(void) {
  printf("%ld",_40_main());
  return 0;
}
