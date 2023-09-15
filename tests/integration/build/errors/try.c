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

/* Function forward definitions */
int64_t _2_main();
struct0 _4_f(uint8_t _4_fail);
struct0 _9_g();

/* Function definitions */
int64_t _2_main() {
    struct0 _2_t1;
    int64_t _2_t0;
    struct0 _2_t7;
    int64_t _2_t6;
    int64_t _2_$retval;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _2_t1 = _4_f(1);
    $line_idx--;
    if (_2_t1.tag) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _2_t0 = _2_t1._1;
    goto BB2;
BB7:
    _2_t0 = 122;
BB2:
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _2_t7 = _4_f(0);
    $line_idx--;
    if (_2_t7.tag) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _2_t6 = _2_t7._1;
    goto BB4;
BB6:
    _2_t6 = 122;
BB4:
    _2_$retval = _2_t0 + _2_t6;
    return _2_$retval;
}

struct0 _4_f(uint8_t _4_fail) {
    struct0 _4_t1;
    int64_t _7_x;
    struct0 _4_t0;
    struct0 _4_$retval;
    if (_4_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _4_t1 = _9_g();
    $line_idx--;
    if (_4_t1.tag) {
        goto BB2;
    } else {
        goto BB7;
    }
BB8:
    _4_t0 = (struct0) {.tag=1, ._1=0};
    goto BB6;
BB2:
    _7_x = _4_t1._1;
    _4_t0 = (struct0) {.tag=1, ._1=_7_x};
    goto BB6;
BB7:
    _4_$retval = _4_t1;
    return _4_$retval;
BB6:
    _4_$retval = _4_t0;
    return _4_$retval;
}

struct0 _9_g() {
    struct0 _9_$retval;
    _9_$retval = (struct0) {.tag=0};
    return _9_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
