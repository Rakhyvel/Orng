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
int64_t _297_main(void);
struct1 _299_f(uint8_t _299_fail);
struct1 _304_g(void);

/* Function definitions */
int64_t _297_main(void) {
    function0 _297_t1;
    uint8_t _297_t3;
    struct1 _297_t2;
    uint64_t _297_t4;
    int64_t _297_t0;
    function0 _297_t7;
    uint8_t _297_t9;
    struct1 _297_t8;
    uint64_t _297_t10;
    int64_t _297_t6;
    int64_t _297_$retval;
    _297_t1 = _299_f;
    _297_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _297_t2 = _297_t1(_297_t3);
    $line_idx--;
    _297_t4 = _297_t2.tag;
    if (_297_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _297_t0 = 122;
    goto BB2;
BB7:
    _297_t0 = _297_t2._0;
    goto BB2;
BB2:
    _297_t7 = _299_f;
    _297_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _297_t8 = _297_t7(_297_t9);
    $line_idx--;
    _297_t10 = _297_t8.tag;
    if (_297_t10) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _297_t6 = 122;
    goto BB4;
BB6:
    _297_t6 = _297_t8._0;
    goto BB4;
BB4:
    _297_$retval = $add_int64_t(_297_t0, _297_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _297_$retval;
}

struct1 _299_f(uint8_t _299_fail) {
    function2 _299_t1;
    struct1 _299_t2;
    uint64_t _299_t3;
    struct1 _299_$retval;
    int64_t _299_t5;
    struct1 _299_t0;
    int64_t _302_x;
    if (_299_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _299_t1 = _304_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _299_t2 = _299_t1();
    $line_idx--;
    _299_t3 = _299_t2.tag;
    if (_299_t3) {
        goto BB2;
    } else {
        goto BB4;
    }
BB8:
    _299_t5 = 0;
    _299_t0 = (struct1) {.tag=0, ._0=_299_t5};
    goto BB7;
BB2:
    _299_$retval = _299_t2;
    return _299_$retval;
BB4:
    _302_x = _299_t2._0;
    _299_t0 = (struct1) {.tag=0, ._0=_302_x};
    goto BB7;
BB7:
    _299_$retval = _299_t0;
    return _299_$retval;
}

struct1 _304_g(void) {
    struct1 _304_$retval;
    _304_$retval = (struct1) {.tag=1};
    return _304_$retval;
}

int main(void) {
  printf("%ld",_297_main());
  return 0;
}
