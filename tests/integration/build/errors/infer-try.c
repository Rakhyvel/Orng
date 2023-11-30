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
int64_t _500_main(void);
struct1 _505_f(void);
struct1 _507_g(void);

/* Function definitions */
int64_t _500_main(void) {
    function0 _500_t1;
    struct1 _500_t2;
    uint64_t _500_t3;
    uint64_t _500_t4;
    uint8_t _500_t5;
    int64_t _500_$retval;
    uint64_t _500_t6;
    uint64_t _500_t7;
    uint8_t _500_t8;
    _500_t1 = _505_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _500_t2 = _500_t1();
    $line_idx--;
    _500_t3 = 0;
    _500_t4 = _500_t2.tag;
    _500_t5 = _500_t4 == _500_t3;
    if (_500_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _500_t6 = 1;
    _500_t7 = _500_t2.tag;
    _500_t8 = _500_t7 == _500_t6;
    if (_500_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _500_$retval = 239;
    return _500_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _505_f(void) {
    function0 _505_t0;
    struct1 _505_t1;
    uint64_t _505_t2;
    struct1 _505_$retval;
    _505_t0 = _507_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _505_t1 = _505_t0();
    $line_idx--;
    _505_t2 = _505_t1.tag;
    if (_505_t2) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _505_$retval = _505_t1;
    return _505_$retval;
BB3:
    _505_$retval = (struct1) {.tag=0, ._0=(_505_t1._0)};
    return _505_$retval;
}

struct1 _507_g(void) {
    struct1 _507_$retval;
    _507_$retval = (struct1) {.tag=1};
    return _507_$retval;
}

int main(void) {
  printf("%ld",_500_main());
  return 0;
}
