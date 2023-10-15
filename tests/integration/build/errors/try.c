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
} struct0;

/* Function forward definitions */
int64_t _1_main(void);
struct0 _3_f(uint8_t _3_fail);
struct0 _8_g(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t1;
    int64_t _1_t0;
    struct0 _1_t7;
    int64_t _1_t6;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _1_t1 = _3_f(1);
    $line_idx--;
    if (_1_t1.tag) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _1_t0 = 122;
    goto BB2;
BB7:
    _1_t0 = _1_t1._0;
BB2:
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _1_t7 = _3_f(0);
    $line_idx--;
    if (_1_t7.tag) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _1_t6 = 122;
    goto BB4;
BB6:
    _1_t6 = _1_t7._0;
BB4:
    _1_$retval = $add_int64_t(_1_t0, _1_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _1_$retval;
}

struct0 _3_f(uint8_t _3_fail) {
    struct0 _3_t1;
    struct0 _3_$retval;
    int64_t _3_t3;
    struct0 _3_t0;
    if (_3_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _3_t1 = _8_g();
    $line_idx--;
    if (_3_t1.tag) {
        goto BB2;
    } else {
        goto BB3;
    }
BB8:
    _3_t0 = (struct0) {.tag=0, ._0=0};
    goto BB7;
BB2:
    _3_$retval = _3_t1;
    return _3_$retval;
BB3:
    _3_t3 = _3_t1._0;
    _3_t0 = (struct0) {.tag=0, ._0=_3_t3};
BB7:
    _3_$retval = _3_t0;
    return _3_$retval;
}

struct0 _8_g(void) {
    struct0 _8_$retval;
    _8_$retval = (struct0) {.tag=1};
    return _8_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
