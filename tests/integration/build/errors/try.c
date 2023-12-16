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
int64_t _547_main(void);
struct1 _549_f(uint8_t _549_fail);
struct1 _554_g(void);

/* Function definitions */
int64_t _547_main(void) {
    function0 _547_t1;
    uint8_t _547_t3;
    struct1 _547_t2;
    uint64_t _547_t4;
    int64_t _547_t0;
    function0 _547_t7;
    uint8_t _547_t9;
    struct1 _547_t8;
    uint64_t _547_t10;
    int64_t _547_t6;
    int64_t _547_$retval;
    _547_t1 = _549_f;
    _547_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _547_t2 = _547_t1(_547_t3);
    $line_idx--;
    _547_t4 = _547_t2.tag;
    if (_547_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _547_t0 = 122;
    goto BB2;
BB7:
    _547_t0 = _547_t2._0;
    goto BB2;
BB2:
    _547_t7 = _549_f;
    _547_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _547_t8 = _547_t7(_547_t9);
    $line_idx--;
    _547_t10 = _547_t8.tag;
    if (_547_t10) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _547_t6 = 122;
    goto BB4;
BB6:
    _547_t6 = _547_t8._0;
    goto BB4;
BB4:
    _547_$retval = $add_int64_t(_547_t0, _547_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _547_$retval;
}

struct1 _549_f(uint8_t _549_fail) {
    function2 _549_t1;
    struct1 _549_t2;
    uint64_t _549_t3;
    struct1 _549_$retval;
    int64_t _549_t5;
    struct1 _549_t0;
    int64_t _552_x;
    if (_549_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _549_t1 = _554_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _549_t2 = _549_t1();
    $line_idx--;
    _549_t3 = _549_t2.tag;
    if (_549_t3) {
        goto BB2;
    } else {
        goto BB4;
    }
BB8:
    _549_t5 = 0;
    _549_t0 = (struct1) {.tag=0, ._0=_549_t5};
    goto BB7;
BB2:
    _549_$retval = _549_t2;
    return _549_$retval;
BB4:
    _552_x = _549_t2._0;
    _549_t0 = (struct1) {.tag=0, ._0=_552_x};
    goto BB7;
BB7:
    _549_$retval = _549_t0;
    return _549_$retval;
}

struct1 _554_g(void) {
    struct1 _554_$retval;
    _554_$retval = (struct1) {.tag=1};
    return _554_$retval;
}

int main(void) {
  printf("%ld",_547_main());
  return 0;
}
