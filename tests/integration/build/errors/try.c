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
int64_t _497_main(void);
struct1 _499_f(uint8_t _499_fail);
struct1 _505_g(void);

/* Function definitions */
int64_t _497_main(void) {
    function0 _497_t1;
    uint8_t _497_t3;
    struct1 _497_t2;
    uint64_t _497_t4;
    int64_t _497_t0;
    function0 _497_t7;
    uint8_t _497_t9;
    struct1 _497_t8;
    uint64_t _497_t10;
    int64_t _497_t6;
    int64_t _497_$retval;
    _497_t1 = _499_f;
    _497_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _497_t2 = _497_t1(_497_t3);
    $line_idx--;
    _497_t4 = _497_t2.tag;
    if (_497_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _497_t0 = 122;
    goto BB2;
BB7:
    _497_t0 = _497_t2._0;
    goto BB2;
BB2:
    _497_t7 = _499_f;
    _497_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _497_t8 = _497_t7(_497_t9);
    $line_idx--;
    _497_t10 = _497_t8.tag;
    if (_497_t10) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _497_t6 = 122;
    goto BB4;
BB6:
    _497_t6 = _497_t8._0;
    goto BB4;
BB4:
    _497_$retval = $add_int64_t(_497_t0, _497_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _497_$retval;
}

struct1 _499_f(uint8_t _499_fail) {
    function2 _499_t1;
    struct1 _499_t2;
    uint64_t _499_t3;
    struct1 _499_$retval;
    int64_t _499_t5;
    struct1 _499_t0;
    int64_t _503_x;
    if (_499_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _499_t1 = _505_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _499_t2 = _499_t1();
    $line_idx--;
    _499_t3 = _499_t2.tag;
    if (_499_t3) {
        goto BB2;
    } else {
        goto BB4;
    }
BB8:
    _499_t5 = 0;
    _499_t0 = (struct1) {.tag=0, ._0=_499_t5};
    goto BB7;
BB2:
    _499_$retval = _499_t2;
    return _499_$retval;
BB4:
    _503_x = _499_t2._0;
    _499_t0 = (struct1) {.tag=0, ._0=_503_x};
    goto BB7;
BB7:
    _499_$retval = _499_t0;
    return _499_$retval;
}

struct1 _505_g(void) {
    struct1 _505_$retval;
    _505_$retval = (struct1) {.tag=1};
    return _505_$retval;
}

int main(void) {
  printf("%ld",_497_main());
  return 0;
}
