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
int64_t _36_main(void);
struct1 _41_f(void);
struct1 _43_g(void);

/* Function definitions */
int64_t _36_main(void) {
    function0 _36_t1;
    struct1 _36_t2;
    uint64_t _36_t3;
    uint64_t _36_t4;
    uint8_t _36_t5;
    int64_t _36_$retval;
    uint64_t _36_t6;
    uint64_t _36_t7;
    uint8_t _36_t8;
    _36_t1 = _41_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _36_t2 = _36_t1();
    $line_idx--;
    _36_t3 = 0;
    _36_t4 = _36_t2.tag;
    _36_t5 = _36_t4 == _36_t3;
    if (_36_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _36_t6 = 1;
    _36_t7 = _36_t2.tag;
    _36_t8 = _36_t7 == _36_t6;
    if (_36_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _36_$retval = 239;
    return _36_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _41_f(void) {
    function0 _41_t0;
    struct1 _41_t1;
    uint64_t _41_t2;
    struct1 _41_$retval;
    _41_t0 = _43_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _41_t1 = _41_t0();
    $line_idx--;
    _41_t2 = _41_t1.tag;
    if (_41_t2) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _41_$retval = _41_t1;
    return _41_$retval;
BB3:
    _41_$retval = (struct1) {.tag=0, ._0=(_41_t1._0)};
    return _41_$retval;
}

struct1 _43_g(void) {
    struct1 _43_$retval;
    _43_$retval = (struct1) {.tag=1};
    return _43_$retval;
}

int main(void) {
  printf("%ld",_36_main());
  return 0;
}
