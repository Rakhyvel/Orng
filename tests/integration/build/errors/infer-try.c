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
int64_t _351_main(void);
struct1 _356_f(void);
struct1 _358_g(void);

/* Function definitions */
int64_t _351_main(void) {
    function0 _351_t1;
    struct1 _351_t2;
    uint64_t _351_t3;
    uint64_t _351_t4;
    uint8_t _351_t5;
    int64_t _351_$retval;
    uint64_t _351_t6;
    uint64_t _351_t7;
    uint8_t _351_t8;
    _351_t1 = _356_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _351_t2 = _351_t1();
    $line_idx--;
    _351_t3 = 0;
    _351_t4 = _351_t2.tag;
    _351_t5 = _351_t4 == _351_t3;
    if (_351_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _351_t6 = 1;
    _351_t7 = _351_t2.tag;
    _351_t8 = _351_t7 == _351_t6;
    if (_351_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _351_$retval = 239;
    return _351_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _356_f(void) {
    function0 _356_t0;
    struct1 _356_t1;
    uint64_t _356_t2;
    struct1 _356_$retval;
    _356_t0 = _358_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _356_t1 = _356_t0();
    $line_idx--;
    _356_t2 = _356_t1.tag;
    if (_356_t2) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _356_$retval = _356_t1;
    return _356_$retval;
BB3:
    _356_$retval = (struct1) {.tag=0, ._0=(_356_t1._0)};
    return _356_$retval;
}

struct1 _358_g(void) {
    struct1 _358_$retval;
    _358_$retval = (struct1) {.tag=1};
    return _358_$retval;
}

int main(void) {
  printf("%ld",_351_main());
  return 0;
}
