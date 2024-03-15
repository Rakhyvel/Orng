/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    uint64_t tag;
    union {
        int64_t _0;
        int64_t _1;
    };
};

typedef struct struct1(*function0)(uint8_t);

/* Function forward definitions */
int64_t _25_main(void);
struct struct1 _32_f(uint8_t _32_give_int);


/* Function definitions */
int64_t _25_main(void){
    function0 _25_t1;
    uint8_t _25_t3;
    struct struct1 _25_t2;
    uint64_t _25_t4;
    uint64_t _25_t5;
    uint8_t _25_t6;
    uint64_t _25_t10;
    uint64_t _25_t11;
    uint8_t _25_t12;
    uint64_t _25_t7;
    uint64_t _25_t8;
    uint8_t _25_t9;
    int64_t _25_$retval;
    _25_t1 = (function0) _32_f;
    _25_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:3:13:\n    match f(true) {\n           ^";
    _25_t2 = _25_t1(_25_t3);
    $line_idx--;
    _25_t4 = 0;
    _25_t5 = _25_t2.tag;
    _25_t6 = _25_t5==_25_t4;
    if (_25_t6) {
        goto BB39;
    } else {
        goto BB40;
    }
BB39:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB40:
    _25_t7 = 2;
    _25_t8 = _25_t2.tag;
    _25_t9 = _25_t8==_25_t7;
    if (_25_t9) {
        goto BB42;
    } else {
        goto BB43;
    }
BB42:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:5:32:\n        .error_1 => unreachable\n                              ^";
    $panic("reached unreachable code\n");
BB43:
    _25_t10 = 1;
    _25_t11 = _25_t2.tag;
    _25_t12 = _25_t11==_25_t10;
    if (_25_t12) {
        goto BB45;
    } else {
        goto BB49;
    }
BB45:
    _25_$retval = _25_t2._1;
    return _25_$retval;
BB49:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:7:25:\n        _ => unreachable\n                       ^";
    $panic("reached unreachable code\n");
}

struct struct1 _32_f(uint8_t _32_give_int){
    int64_t _32_t1;
    struct struct1 _32_t0;
    struct struct1 _32_$retval;
    if (_32_give_int) {
        goto BB30;
    } else {
        goto BB34;
    }
BB30:
    _32_t1 = 240;
    _32_t0 = (struct struct1) {.tag=1, ._1=_32_t1};
    goto BB33;
BB34:
    _32_t0 = (struct struct1) {.tag=2};
    goto BB33;
BB33:
    _32_$retval = _32_t0;
    return _32_$retval;
}


int main(void) {
  printf("%ld",_25_main());
  return 0;
}
