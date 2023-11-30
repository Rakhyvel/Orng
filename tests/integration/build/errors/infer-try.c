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
} struct1;

typedef struct1(*function0)(void);

/* Function forward definitions */
int64_t _477_main(void);
struct1 _482_f(void);
struct1 _484_g(void);

/* Function definitions */
int64_t _477_main(void) {
    function0 _477_t1;
    struct1 _477_t2;
    uint64_t _477_t3;
    uint64_t _477_t4;
    uint8_t _477_t5;
    int64_t _477_$retval;
    uint64_t _477_t6;
    uint64_t _477_t7;
    uint8_t _477_t8;
    _477_t1 = _482_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _477_t2 = _477_t1();
    $line_idx--;
    _477_t3 = 0;
    _477_t4 = _477_t2.tag;
    _477_t5 = _477_t4 == _477_t3;
    if (_477_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _477_t6 = 1;
    _477_t7 = _477_t2.tag;
    _477_t8 = _477_t7 == _477_t6;
    if (_477_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _477_$retval = 239;
    return _477_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _482_f(void) {
    function0 _482_t0;
    struct1 _482_t1;
    uint64_t _482_t2;
    struct1 _482_$retval;
    _482_t0 = _484_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _482_t1 = _482_t0();
    $line_idx--;
    _482_t2 = _482_t1.tag;
    if (_482_t2) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _482_$retval = _482_t1;
    return _482_$retval;
BB3:
    _482_$retval = (struct1) {.tag=0, ._0=(_482_t1._0)};
    return _482_$retval;
}

struct1 _484_g(void) {
    struct1 _484_$retval;
    _484_$retval = (struct1) {.tag=1};
    return _484_$retval;
}

int main(void) {
  printf("%ld",_477_main());
  return 0;
}
