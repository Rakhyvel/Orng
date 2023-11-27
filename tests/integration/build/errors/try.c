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
int64_t _328_main(void);
struct1 _330_f(uint8_t _330_fail);
struct1 _335_g(void);

/* Function definitions */
int64_t _328_main(void) {
    function0 _328_t1;
    uint8_t _328_t3;
    struct1 _328_t2;
    uint64_t _328_t4;
    int64_t _328_t0;
    function0 _328_t7;
    uint8_t _328_t9;
    struct1 _328_t8;
    uint64_t _328_t10;
    int64_t _328_t6;
    int64_t _328_$retval;
    _328_t1 = _330_f;
    _328_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _328_t2 = _328_t1(_328_t3);
    $line_idx--;
    _328_t4 = _328_t2.tag;
    if (_328_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _328_t0 = 122;
    goto BB2;
BB7:
    _328_t0 = _328_t2._0;
    goto BB2;
BB2:
    _328_t7 = _330_f;
    _328_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _328_t8 = _328_t7(_328_t9);
    $line_idx--;
    _328_t10 = _328_t8.tag;
    if (_328_t10) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _328_t6 = 122;
    goto BB4;
BB6:
    _328_t6 = _328_t8._0;
    goto BB4;
BB4:
    _328_$retval = $add_int64_t(_328_t0, _328_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _328_$retval;
}

struct1 _330_f(uint8_t _330_fail) {
    function2 _330_t1;
    struct1 _330_t2;
    uint64_t _330_t3;
    struct1 _330_$retval;
    int64_t _330_t5;
    struct1 _330_t0;
    int64_t _333_x;
    if (_330_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _330_t1 = _335_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _330_t2 = _330_t1();
    $line_idx--;
    _330_t3 = _330_t2.tag;
    if (_330_t3) {
        goto BB2;
    } else {
        goto BB4;
    }
BB8:
    _330_t5 = 0;
    _330_t0 = (struct1) {.tag=0, ._0=_330_t5};
    goto BB7;
BB2:
    _330_$retval = _330_t2;
    return _330_$retval;
BB4:
    _333_x = _330_t2._0;
    _330_t0 = (struct1) {.tag=0, ._0=_333_x};
    goto BB7;
BB7:
    _330_$retval = _330_t0;
    return _330_$retval;
}

struct1 _335_g(void) {
    struct1 _335_$retval;
    _335_$retval = (struct1) {.tag=1};
    return _335_$retval;
}

int main(void) {
  printf("%ld",_328_main());
  return 0;
}
