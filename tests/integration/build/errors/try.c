/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _1;
    };
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
struct0 _4_f(uint8_t _4_fail);
struct0 _9_g();

/* Function definitions */
int64_t _2_main() {
    uint8_t _2_t2;
    struct0 _2_t1;
    uint8_t _2_t3;
    int64_t _2_t0;
    uint8_t _2_t8;
    struct0 _2_t7;
    uint8_t _2_t9;
    int64_t _2_t6;
    int64_t _2_$retval;
BB0:
    _2_t2 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _2_t1 = _4_f(_2_t2);
    $line_idx--;
    _2_t3 = _2_t1.tag;
    if (_2_t3) {
        goto BB1;
    } else {
        goto BB7;
    }
BB7:
    _2_t0 = 122;
    goto BB2;
BB2:
    _2_t8 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _2_t7 = _4_f(_2_t8);
    $line_idx--;
    _2_t9 = _2_t7.tag;
    if (_2_t9) {
        goto BB3;
    } else {
        goto BB6;
    }
BB6:
    _2_t6 = 122;
    goto BB4;
BB4:
    _2_$retval = _2_t0 + _2_t6;
    return _2_$retval;
BB3:
    _2_t6 = (&_2_t7)->_1;
    goto BB4;
BB1:
    _2_t0 = (&_2_t1)->_1;
    goto BB2;
}

struct0 _4_f(uint8_t _4_fail) {
    struct0 _4_t1;
    uint8_t _4_t2;
    int64_t _7_x;
    struct0 _4_t0;
    struct0 _4_$retval;
    int64_t _4_t5;
BB0:
    if (_4_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB8:
    _4_t5 = 0;
    _4_t0 = (struct0) {.tag=1, ._1=_4_t5};
    goto BB6;
BB6:
    _4_$retval = _4_t0;
    return _4_$retval;
BB1:
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _4_t1 = _9_g();
    $line_idx--;
    _4_t2 = _4_t1.tag;
    if (_4_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB7:
    _4_$retval = _4_t1;
    return _4_$retval;
BB2:
    _7_x = (&_4_t1)->_1;
    _4_t0 = (struct0) {.tag=1, ._1=_7_x};
    goto BB6;
}

struct0 _9_g() {
    struct0 _9_$retval;
BB0:
    _9_$retval = (struct0) {.tag=0};
    return _9_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

