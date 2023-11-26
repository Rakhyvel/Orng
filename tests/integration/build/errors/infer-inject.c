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
} struct1;

typedef struct1(*function0)(uint8_t);

/* Function forward definitions */
int64_t _259_main(void);
struct1 _265_f(uint8_t _265_give_int);

/* Function definitions */
int64_t _259_main(void) {
    function0 _259_t1;
    uint8_t _259_t3;
    struct1 _259_t2;
    uint64_t _259_t4;
    uint64_t _259_t5;
    uint8_t _259_t6;
    uint64_t _259_t10;
    uint64_t _259_t11;
    uint8_t _259_t12;
    uint64_t _259_t7;
    uint64_t _259_t8;
    uint8_t _259_t9;
    int64_t _259_$retval;
    _259_t1 = _265_f;
    _259_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:3:13:\n    match f(true) {\n           ^";
    _259_t2 = _259_t1(_259_t3);
    $line_idx--;
    _259_t4 = 0;
    _259_t5 = _259_t2.tag;
    _259_t6 = _259_t5 == _259_t4;
    if (_259_t6) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _259_t7 = 2;
    _259_t8 = _259_t2.tag;
    _259_t9 = _259_t8 == _259_t7;
    if (_259_t9) {
        goto BB6;
    } else {
        goto BB7;
    }
BB6:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:5:32:\n        .error_1 => unreachable\n                              ^";
    $panic("reached unreachable code\n");
BB7:
    _259_t10 = 1;
    _259_t11 = _259_t2.tag;
    _259_t12 = _259_t11 == _259_t10;
    if (_259_t12) {
        goto BB9;
    } else {
        goto BB13;
    }
BB9:
    _259_$retval = _259_t2._1;
    return _259_$retval;
BB13:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:7:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _265_f(uint8_t _265_give_int) {
    int64_t _265_t1;
    struct1 _265_t0;
    struct1 _265_$retval;
    if (_265_give_int) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _265_t1 = 240;
    _265_t0 = (struct1) {.tag=1, ._1=_265_t1};
    goto BB4;
BB5:
    _265_t0 = (struct1) {.tag=2};
    goto BB4;
BB4:
    _265_$retval = _265_t0;
    return _265_$retval;
}

int main(void) {
  printf("%ld",_259_main());
  return 0;
}
