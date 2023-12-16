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
int64_t _555_main(void);
struct1 _557_f(uint8_t _557_fail);
struct1 _562_g(void);

/* Function definitions */
int64_t _555_main(void){
    function0 _555_t1;
    uint8_t _555_t3;
    struct1 _555_t2;
    uint64_t _555_t4;
    int64_t _555_t0;
    function0 _555_t7;
    uint8_t _555_t9;
    struct1 _555_t8;
    uint64_t _555_t10;
    int64_t _555_t6;
    int64_t _555_$retval;
    _555_t1 = _557_f;
    _555_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _555_t2 = _555_t1(_555_t3);
    $line_idx--;
    _555_t4 = _555_t2.tag;
    if (_555_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _555_t0 = 122;
    goto BB2;
BB7:
    _555_t0 = _555_t2._0;
    goto BB2;
BB2:
    _555_t7 = _557_f;
    _555_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _555_t8 = _555_t7(_555_t9);
    $line_idx--;
    _555_t10 = _555_t8.tag;
    if (_555_t10) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _555_t6 = 122;
    goto BB4;
BB6:
    _555_t6 = _555_t8._0;
    goto BB4;
BB4:
    _555_$retval = $add_int64_t(_555_t0, _555_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _555_$retval;
}

struct1 _557_f(uint8_t _557_fail){
    function2 _557_t1;
    struct1 _557_t2;
    uint64_t _557_t3;
    struct1 _557_$retval;
    int64_t _557_t5;
    struct1 _557_t0;
    int64_t _560_x;
    if (_557_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _557_t1 = _562_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _557_t2 = _557_t1();
    $line_idx--;
    _557_t3 = _557_t2.tag;
    if (_557_t3) {
        goto BB2;
    } else {
        goto BB4;
    }
BB8:
    _557_t5 = 0;
    _557_t0 = (struct1) {.tag=0, ._0=_557_t5};
    goto BB7;
BB2:
    _557_$retval = _557_t2;
    return _557_$retval;
BB4:
    _560_x = _557_t2._0;
    _557_t0 = (struct1) {.tag=0, ._0=_560_x};
    goto BB7;
BB7:
    _557_$retval = _557_t0;
    return _557_$retval;
}

struct1 _562_g(void){
    struct1 _562_$retval;
    _562_$retval = (struct1) {.tag=1};
    return _562_$retval;
}

int main(void) {
  printf("%ld",_555_main());
  return 0;
}
