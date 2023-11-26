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
int64_t _279_main(void);
struct1 _284_f(void);
struct1 _286_g(void);

/* Function definitions */
int64_t _279_main(void) {
    function0 _279_t1;
    struct1 _279_t2;
    uint64_t _279_t3;
    uint64_t _279_t4;
    uint8_t _279_t5;
    int64_t _279_$retval;
    uint64_t _279_t6;
    uint64_t _279_t7;
    uint8_t _279_t8;
    _279_t1 = _284_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _279_t2 = _279_t1();
    $line_idx--;
    _279_t3 = 0;
    _279_t4 = _279_t2.tag;
    _279_t5 = _279_t4 == _279_t3;
    if (_279_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _279_t6 = 1;
    _279_t7 = _279_t2.tag;
    _279_t8 = _279_t7 == _279_t6;
    if (_279_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _279_$retval = 239;
    return _279_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _284_f(void) {
    function0 _284_t0;
    struct1 _284_t1;
    uint64_t _284_t2;
    struct1 _284_$retval;
    _284_t0 = _286_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _284_t1 = _284_t0();
    $line_idx--;
    _284_t2 = _284_t1.tag;
    if (_284_t2) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _284_$retval = _284_t1;
    return _284_$retval;
BB3:
    _284_$retval = (struct1) {.tag=0, ._0=(_284_t1._0)};
    return _284_$retval;
}

struct1 _286_g(void) {
    struct1 _286_$retval;
    _286_$retval = (struct1) {.tag=1};
    return _286_$retval;
}

int main(void) {
  printf("%ld",_279_main());
  return 0;
}
