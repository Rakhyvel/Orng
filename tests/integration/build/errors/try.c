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
int64_t _400_main(void);
struct1 _402_f(uint8_t _402_fail);
struct1 _407_g(void);

/* Function definitions */
int64_t _400_main(void) {
    function0 _400_t1;
    uint8_t _400_t3;
    struct1 _400_t2;
    uint64_t _400_t4;
    int64_t _400_t0;
    function0 _400_t7;
    uint8_t _400_t9;
    struct1 _400_t8;
    uint64_t _400_t10;
    int64_t _400_t6;
    int64_t _400_$retval;
    _400_t1 = _402_f;
    _400_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _400_t2 = _400_t1(_400_t3);
    $line_idx--;
    _400_t4 = _400_t2.tag;
    if (_400_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _400_t0 = 122;
    goto BB2;
BB7:
    _400_t0 = _400_t2._0;
    goto BB2;
BB2:
    _400_t7 = _402_f;
    _400_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _400_t8 = _400_t7(_400_t9);
    $line_idx--;
    _400_t10 = _400_t8.tag;
    if (_400_t10) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _400_t6 = 122;
    goto BB4;
BB6:
    _400_t6 = _400_t8._0;
    goto BB4;
BB4:
    _400_$retval = $add_int64_t(_400_t0, _400_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _400_$retval;
}

struct1 _402_f(uint8_t _402_fail) {
    function2 _402_t1;
    struct1 _402_t2;
    uint64_t _402_t3;
    struct1 _402_$retval;
    int64_t _402_t5;
    struct1 _402_t0;
    int64_t _405_x;
    if (_402_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _402_t1 = _407_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _402_t2 = _402_t1();
    $line_idx--;
    _402_t3 = _402_t2.tag;
    if (_402_t3) {
        goto BB2;
    } else {
        goto BB4;
    }
BB8:
    _402_t5 = 0;
    _402_t0 = (struct1) {.tag=0, ._0=_402_t5};
    goto BB7;
BB2:
    _402_$retval = _402_t2;
    return _402_$retval;
BB4:
    _405_x = _402_t2._0;
    _402_t0 = (struct1) {.tag=0, ._0=_405_x};
    goto BB7;
BB7:
    _402_$retval = _402_t0;
    return _402_$retval;
}

struct1 _407_g(void) {
    struct1 _407_$retval;
    _407_$retval = (struct1) {.tag=1};
    return _407_$retval;
}

int main(void) {
  printf("%ld",_400_main());
  return 0;
}
