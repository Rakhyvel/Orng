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
int64_t _370_main(void);
struct1 _375_f(void);
struct1 _377_g(void);

/* Function definitions */
int64_t _370_main(void) {
    function0 _370_t1;
    struct1 _370_t2;
    uint64_t _370_t3;
    uint64_t _370_t4;
    uint8_t _370_t5;
    int64_t _370_$retval;
    uint64_t _370_t6;
    uint64_t _370_t7;
    uint8_t _370_t8;
    _370_t1 = _375_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _370_t2 = _370_t1();
    $line_idx--;
    _370_t3 = 0;
    _370_t4 = _370_t2.tag;
    _370_t5 = _370_t4 == _370_t3;
    if (_370_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _370_t6 = 1;
    _370_t7 = _370_t2.tag;
    _370_t8 = _370_t7 == _370_t6;
    if (_370_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _370_$retval = 239;
    return _370_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _375_f(void) {
    function0 _375_t0;
    struct1 _375_t1;
    uint64_t _375_t2;
    struct1 _375_$retval;
    _375_t0 = _377_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _375_t1 = _375_t0();
    $line_idx--;
    _375_t2 = _375_t1.tag;
    if (_375_t2) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _375_$retval = _375_t1;
    return _375_$retval;
BB3:
    _375_$retval = (struct1) {.tag=0, ._0=(_375_t1._0)};
    return _375_$retval;
}

struct1 _377_g(void) {
    struct1 _377_$retval;
    _377_$retval = (struct1) {.tag=1};
    return _377_$retval;
}

int main(void) {
  printf("%ld",_370_main());
  return 0;
}
