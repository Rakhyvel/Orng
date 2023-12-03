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
int64_t _343_main(void);
struct1 _348_f(void);
struct1 _350_g(void);

/* Function definitions */
int64_t _343_main(void) {
    function0 _343_t1;
    struct1 _343_t2;
    uint64_t _343_t3;
    uint64_t _343_t4;
    uint8_t _343_t5;
    int64_t _343_$retval;
    uint64_t _343_t6;
    uint64_t _343_t7;
    uint8_t _343_t8;
    _343_t1 = _348_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _343_t2 = _343_t1();
    $line_idx--;
    _343_t3 = 0;
    _343_t4 = _343_t2.tag;
    _343_t5 = _343_t4 == _343_t3;
    if (_343_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _343_t6 = 1;
    _343_t7 = _343_t2.tag;
    _343_t8 = _343_t7 == _343_t6;
    if (_343_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _343_$retval = 239;
    return _343_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _348_f(void) {
    function0 _348_t0;
    struct1 _348_t1;
    uint64_t _348_t2;
    struct1 _348_$retval;
    _348_t0 = _350_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _348_t1 = _348_t0();
    $line_idx--;
    _348_t2 = _348_t1.tag;
    if (_348_t2) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _348_$retval = _348_t1;
    return _348_$retval;
BB3:
    _348_$retval = (struct1) {.tag=0, ._0=(_348_t1._0)};
    return _348_$retval;
}

struct1 _350_g(void) {
    struct1 _350_$retval;
    _350_$retval = (struct1) {.tag=1};
    return _350_$retval;
}

int main(void) {
  printf("%ld",_343_main());
  return 0;
}
