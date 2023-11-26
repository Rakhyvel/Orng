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
int64_t _1020_main(void);
struct1 _1025_f(void);

/* Function definitions */
int64_t _1020_main(void) {
    function0 _1020_t1;
    struct1 _1020_t2;
    function0 _1020_t3;
    struct1 _1020_t4;
    uint64_t _1020_t7;
    uint64_t _1020_t8;
    uint8_t _1020_t6;
    uint8_t _1020_t5;
    int64_t _1020_t0;
    int64_t _1020_$retval;
    _1020_t1 = _1025_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1020_t2 = _1020_t1();
    $line_idx--;
    _1020_t3 = _1025_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1020_t4 = _1020_t3();
    $line_idx--;
    _1020_t7 = _1020_t2.tag;
    _1020_t8 = _1020_t4.tag;
    _1020_t6 = _1020_t7 == _1020_t8;
    if (_1020_t6) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _1020_t5 = 1;
    goto BB2;
BB9:
    _1020_t5 = 0;
    goto BB2;
BB2:
    if (_1020_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1020_t0 = 212;
    goto BB6;
BB7:
    _1020_t0 = -1;
    goto BB6;
BB6:
    _1020_$retval = _1020_t0;
    return _1020_$retval;
}

struct1 _1025_f(void) {
    struct1 _1025_$retval;
    _1025_$retval = (struct1) {.tag=0};
    return _1025_$retval;
}

int main(void) {
  printf("%ld",_1020_main());
  return 0;
}
