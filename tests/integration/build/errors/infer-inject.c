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
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _1_main(void);
struct0 _7_f(uint8_t _7_give_int);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t1;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:3:13:\n    match f(true) {\n           ^";
    _1_t1 = _7_f(1);
    $line_idx--;
    if (_1_t1.tag) {
        goto BB4;
    } else {
        goto BB3;
    }
BB4:
    if (_1_t1.tag == 2) {
        goto BB6;
    } else {
        goto BB7;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB6:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:5:32:\n        .error_1 => unreachable\n                              ^";
    $panic("reached unreachable code\n");
BB7:
    if (_1_t1.tag == 1) {
        goto BB9;
    } else {
        goto BB13;
    }
BB9:
    _1_$retval = _1_t1._0;
    return _1_$retval;
BB13:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:7:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct0 _7_f(uint8_t _7_give_int) {
    struct0 _7_t0;
    struct0 _7_$retval;
    if (_7_give_int) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _7_t0 = (struct0) {.tag=1, ._1=240};
    goto BB4;
BB5:
    _7_t0 = (struct0) {.tag=2};
BB4:
    _7_$retval = _7_t0;
    return _7_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
