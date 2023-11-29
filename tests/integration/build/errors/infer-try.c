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
int64_t _382_main(void);
struct1 _387_f(void);
struct1 _389_g(void);

/* Function definitions */
int64_t _382_main(void) {
    function0 _382_t1;
    struct1 _382_t2;
    uint64_t _382_t3;
    uint64_t _382_t4;
    uint8_t _382_t5;
    int64_t _382_$retval;
    uint64_t _382_t6;
    uint64_t _382_t7;
    uint8_t _382_t8;
    _382_t1 = _387_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _382_t2 = _382_t1();
    $line_idx--;
    _382_t3 = 0;
    _382_t4 = _382_t2.tag;
    _382_t5 = _382_t4 == _382_t3;
    if (_382_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _382_t6 = 1;
    _382_t7 = _382_t2.tag;
    _382_t8 = _382_t7 == _382_t6;
    if (_382_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _382_$retval = 239;
    return _382_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _387_f(void) {
    function0 _387_t0;
    struct1 _387_t1;
    uint64_t _387_t2;
    struct1 _387_$retval;
    _387_t0 = _389_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _387_t1 = _387_t0();
    $line_idx--;
    _387_t2 = _387_t1.tag;
    if (_387_t2) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _387_$retval = _387_t1;
    return _387_$retval;
BB3:
    _387_$retval = (struct1) {.tag=0, ._0=(_387_t1._0)};
    return _387_$retval;
}

struct1 _389_g(void) {
    struct1 _389_$retval;
    _389_$retval = (struct1) {.tag=1};
    return _389_$retval;
}

int main(void) {
  printf("%ld",_382_main());
  return 0;
}
