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
int64_t _498_main(void);
struct1 _503_f(void);
struct1 _505_g(void);

/* Function definitions */
int64_t _498_main(void) {
    function0 _498_t1;
    struct1 _498_t2;
    uint64_t _498_t3;
    uint64_t _498_t4;
    uint8_t _498_t5;
    int64_t _498_$retval;
    uint64_t _498_t6;
    uint64_t _498_t7;
    uint8_t _498_t8;
    _498_t1 = _503_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _498_t2 = _498_t1();
    $line_idx--;
    _498_t3 = 0;
    _498_t4 = _498_t2.tag;
    _498_t5 = _498_t4 == _498_t3;
    if (_498_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _498_t6 = 1;
    _498_t7 = _498_t2.tag;
    _498_t8 = _498_t7 == _498_t6;
    if (_498_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _498_$retval = 239;
    return _498_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _503_f(void) {
    function0 _503_t0;
    struct1 _503_t1;
    uint64_t _503_t2;
    struct1 _503_$retval;
    _503_t0 = _505_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _503_t1 = _503_t0();
    $line_idx--;
    _503_t2 = _503_t1.tag;
    if (_503_t2) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _503_$retval = _503_t1;
    return _503_$retval;
BB3:
    _503_$retval = (struct1) {.tag=0, ._0=(_503_t1._0)};
    return _503_$retval;
}

struct1 _505_g(void) {
    struct1 _505_$retval;
    _505_$retval = (struct1) {.tag=1};
    return _505_$retval;
}

int main(void) {
  printf("%ld",_498_main());
  return 0;
}
