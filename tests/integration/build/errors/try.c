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
int64_t _520_main(void);
struct1 _522_f(uint8_t _522_fail);
struct1 _528_g(void);

/* Function definitions */
int64_t _520_main(void) {
    function0 _520_t1;
    uint8_t _520_t3;
    struct1 _520_t2;
    uint64_t _520_t4;
    int64_t _520_t0;
    function0 _520_t7;
    uint8_t _520_t9;
    struct1 _520_t8;
    uint64_t _520_t10;
    int64_t _520_t6;
    int64_t _520_$retval;
    _520_t1 = _522_f;
    _520_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _520_t2 = _520_t1(_520_t3);
    $line_idx--;
    _520_t4 = _520_t2.tag;
    if (_520_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _520_t0 = 122;
    goto BB2;
BB7:
    _520_t0 = _520_t2._0;
    goto BB2;
BB2:
    _520_t7 = _522_f;
    _520_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _520_t8 = _520_t7(_520_t9);
    $line_idx--;
    _520_t10 = _520_t8.tag;
    if (_520_t10) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _520_t6 = 122;
    goto BB4;
BB6:
    _520_t6 = _520_t8._0;
    goto BB4;
BB4:
    _520_$retval = $add_int64_t(_520_t0, _520_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _520_$retval;
}

struct1 _522_f(uint8_t _522_fail) {
    function2 _522_t1;
    struct1 _522_t2;
    uint64_t _522_t3;
    struct1 _522_$retval;
    int64_t _522_t5;
    struct1 _522_t0;
    int64_t _526_x;
    if (_522_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _522_t1 = _528_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _522_t2 = _522_t1();
    $line_idx--;
    _522_t3 = _522_t2.tag;
    if (_522_t3) {
        goto BB2;
    } else {
        goto BB4;
    }
BB8:
    _522_t5 = 0;
    _522_t0 = (struct1) {.tag=0, ._0=_522_t5};
    goto BB7;
BB2:
    _522_$retval = _522_t2;
    return _522_$retval;
BB4:
    _526_x = _522_t2._0;
    _522_t0 = (struct1) {.tag=0, ._0=_526_x};
    goto BB7;
BB7:
    _522_$retval = _522_t0;
    return _522_$retval;
}

struct1 _528_g(void) {
    struct1 _528_$retval;
    _528_$retval = (struct1) {.tag=1};
    return _528_$retval;
}

int main(void) {
  printf("%ld",_520_main());
  return 0;
}
