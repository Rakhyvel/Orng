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

typedef struct1(*function0)(uint8_t);

typedef struct1(*function2)(void);

/* Function forward definitions */
int64_t _54_main(void);
struct1 _56_f(uint8_t _56_fail);
struct1 _61_g(void);

/* Function definitions */
int64_t _54_main(void) {
    function0 _54_t1;
    uint8_t _54_t3;
    struct1 _54_t2;
    uint64_t _54_t4;
    int64_t _54_t0;
    function0 _54_t7;
    uint8_t _54_t9;
    struct1 _54_t8;
    uint64_t _54_t10;
    int64_t _54_t6;
    int64_t _54_$retval;
    _54_t1 = _56_f;
    _54_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _54_t2 = _54_t1(_54_t3);
    $line_idx--;
    _54_t4 = _54_t2.tag;
    if (_54_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _54_t0 = 122;
    goto BB2;
BB7:
    _54_t0 = _54_t2._0;
    goto BB2;
BB2:
    _54_t7 = _56_f;
    _54_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _54_t8 = _54_t7(_54_t9);
    $line_idx--;
    _54_t10 = _54_t8.tag;
    if (_54_t10) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _54_t6 = 122;
    goto BB4;
BB6:
    _54_t6 = _54_t8._0;
    goto BB4;
BB4:
    _54_$retval = $add_int64_t(_54_t0, _54_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _54_$retval;
}

struct1 _56_f(uint8_t _56_fail) {
    function2 _56_t1;
    struct1 _56_t2;
    uint64_t _56_t3;
    struct1 _56_$retval;
    int64_t _56_t5;
    struct1 _56_t0;
    int64_t _59_x;
    if (_56_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _56_t1 = _61_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _56_t2 = _56_t1();
    $line_idx--;
    _56_t3 = _56_t2.tag;
    if (_56_t3) {
        goto BB2;
    } else {
        goto BB4;
    }
BB8:
    _56_t5 = 0;
    _56_t0 = (struct1) {.tag=0, ._0=_56_t5};
    goto BB7;
BB2:
    _56_$retval = _56_t2;
    return _56_$retval;
BB4:
    _59_x = _56_t2._0;
    _56_t0 = (struct1) {.tag=0, ._0=_59_x};
    goto BB7;
BB7:
    _56_$retval = _56_t0;
    return _56_$retval;
}

struct1 _61_g(void) {
    struct1 _61_$retval;
    _61_$retval = (struct1) {.tag=1};
    return _61_$retval;
}

int main(void) {
  printf("%ld",_54_main());
  return 0;
}
