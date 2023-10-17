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
        int64_t _0;
    };
} struct0;

/* Function forward definitions */
int64_t _1_main(void);
struct0 _6_f(void);
struct0 _8_g(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t1;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _1_t1 = _6_f();
    $line_idx--;
    if (_1_t1.tag) {
        goto BB4;
    } else {
        goto BB3;
    }
BB4:
    if (_1_t1.tag == 1) {
        goto BB6;
    } else {
        goto BB10;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB6:
    _1_$retval = 239;
    return _1_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct0 _6_f(void) {
    struct0 _6_t0;
    struct0 _6_$retval;
    int64_t _6_t2;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _6_t0 = _8_g();
    $line_idx--;
    if (_6_t0.tag) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    _6_$retval = _6_t0;
    return _6_$retval;
BB2:
    _6_t2 = _6_t0._0;
    _6_$retval = (struct0) {.tag=0, ._0=_6_t2};
    return _6_$retval;
}

struct0 _8_g(void) {
    struct0 _8_$retval;
    _8_$retval = (struct0) {.tag=1};
    return _8_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
