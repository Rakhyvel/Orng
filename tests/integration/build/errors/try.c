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
int64_t _518_main(void);
struct1 _520_f(uint8_t _520_fail);
struct1 _526_g(void);

/* Function definitions */
int64_t _518_main(void) {
    function0 _518_t1;
    uint8_t _518_t3;
    struct1 _518_t2;
    uint64_t _518_t4;
    int64_t _518_t0;
    function0 _518_t7;
    uint8_t _518_t9;
    struct1 _518_t8;
    uint64_t _518_t10;
    int64_t _518_t6;
    int64_t _518_$retval;
    _518_t1 = _520_f;
    _518_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _518_t2 = _518_t1(_518_t3);
    $line_idx--;
    _518_t4 = _518_t2.tag;
    if (_518_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _518_t0 = 122;
    goto BB2;
BB7:
    _518_t0 = _518_t2._0;
    goto BB2;
BB2:
    _518_t7 = _520_f;
    _518_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _518_t8 = _518_t7(_518_t9);
    $line_idx--;
    _518_t10 = _518_t8.tag;
    if (_518_t10) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _518_t6 = 122;
    goto BB4;
BB6:
    _518_t6 = _518_t8._0;
    goto BB4;
BB4:
    _518_$retval = $add_int64_t(_518_t0, _518_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _518_$retval;
}

struct1 _520_f(uint8_t _520_fail) {
    function2 _520_t1;
    struct1 _520_t2;
    uint64_t _520_t3;
    struct1 _520_$retval;
    int64_t _520_t5;
    struct1 _520_t0;
    int64_t _524_x;
    if (_520_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _520_t1 = _526_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _520_t2 = _520_t1();
    $line_idx--;
    _520_t3 = _520_t2.tag;
    if (_520_t3) {
        goto BB2;
    } else {
        goto BB4;
    }
BB8:
    _520_t5 = 0;
    _520_t0 = (struct1) {.tag=0, ._0=_520_t5};
    goto BB7;
BB2:
    _520_$retval = _520_t2;
    return _520_$retval;
BB4:
    _524_x = _520_t2._0;
    _520_t0 = (struct1) {.tag=0, ._0=_524_x};
    goto BB7;
BB7:
    _520_$retval = _520_t0;
    return _520_$retval;
}

struct1 _526_g(void) {
    struct1 _526_$retval;
    _526_$retval = (struct1) {.tag=1};
    return _526_$retval;
}

int main(void) {
  printf("%ld",_518_main());
  return 0;
}
