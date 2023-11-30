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
int64_t _456_main(void);
struct1 _462_f(uint8_t _462_give_int);

/* Function definitions */
int64_t _456_main(void) {
    function0 _456_t1;
    uint8_t _456_t3;
    struct1 _456_t2;
    uint64_t _456_t4;
    uint64_t _456_t5;
    uint8_t _456_t6;
    uint64_t _456_t10;
    uint64_t _456_t11;
    uint8_t _456_t12;
    uint64_t _456_t7;
    uint64_t _456_t8;
    uint8_t _456_t9;
    int64_t _456_$retval;
    _456_t1 = _462_f;
    _456_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:3:13:\n    match f(true) {\n           ^";
    _456_t2 = _456_t1(_456_t3);
    $line_idx--;
    _456_t4 = 0;
    _456_t5 = _456_t2.tag;
    _456_t6 = _456_t5 == _456_t4;
    if (_456_t6) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _456_t7 = 2;
    _456_t8 = _456_t2.tag;
    _456_t9 = _456_t8 == _456_t7;
    if (_456_t9) {
        goto BB6;
    } else {
        goto BB7;
    }
BB6:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:5:32:\n        .error_1 => unreachable\n                              ^";
    $panic("reached unreachable code\n");
BB7:
    _456_t10 = 1;
    _456_t11 = _456_t2.tag;
    _456_t12 = _456_t11 == _456_t10;
    if (_456_t12) {
        goto BB9;
    } else {
        goto BB13;
    }
BB9:
    _456_$retval = _456_t2._1;
    return _456_$retval;
BB13:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:7:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _462_f(uint8_t _462_give_int) {
    int64_t _462_t1;
    struct1 _462_t0;
    struct1 _462_$retval;
    if (_462_give_int) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _462_t1 = 240;
    _462_t0 = (struct1) {.tag=1, ._1=_462_t1};
    goto BB4;
BB5:
    _462_t0 = (struct1) {.tag=2};
    goto BB4;
BB4:
    _462_$retval = _462_t0;
    return _462_$retval;
}

int main(void) {
  printf("%ld",_456_main());
  return 0;
}
