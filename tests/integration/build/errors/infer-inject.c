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
int64_t _565_main(void);
struct1 _571_f(uint8_t _571_give_int);

/* Function definitions */
int64_t _565_main(void){
    function0 _565_t1;
    uint8_t _565_t3;
    struct1 _565_t2;
    uint64_t _565_t4;
    uint64_t _565_t5;
    uint8_t _565_t6;
    uint64_t _565_t10;
    uint64_t _565_t11;
    uint8_t _565_t12;
    uint64_t _565_t7;
    uint64_t _565_t8;
    uint8_t _565_t9;
    int64_t _565_$retval;
    _565_t1 = _571_f;
    _565_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:3:13:\n    match f(true) {\n           ^";
    _565_t2 = _565_t1(_565_t3);
    $line_idx--;
    _565_t4 = 0;
    _565_t5 = _565_t2.tag;
    _565_t6 = _565_t5==_565_t4;
    if (_565_t6) {
        goto BB708;
    } else {
        goto BB709;
    }
BB708:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB709:
    _565_t7 = 2;
    _565_t8 = _565_t2.tag;
    _565_t9 = _565_t8==_565_t7;
    if (_565_t9) {
        goto BB711;
    } else {
        goto BB712;
    }
BB711:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:5:32:\n        .error_1 => unreachable\n                              ^";
    $panic("reached unreachable code\n");
BB712:
    _565_t10 = 1;
    _565_t11 = _565_t2.tag;
    _565_t12 = _565_t11==_565_t10;
    if (_565_t12) {
        goto BB714;
    } else {
        goto BB718;
    }
BB714:
    _565_$retval = _565_t2._1;
    return _565_$retval;
BB718:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:7:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _571_f(uint8_t _571_give_int){
    int64_t _571_t1;
    struct1 _571_t0;
    struct1 _571_$retval;
    if (_571_give_int) {
        goto BB699;
    } else {
        goto BB703;
    }
BB699:
    _571_t1 = 240;
    _571_t0 = (struct1) {.tag=1, ._1=_571_t1};
    goto BB702;
BB703:
    _571_t0 = (struct1) {.tag=2};
    goto BB702;
BB702:
    _571_$retval = _571_t0;
    return _571_$retval;
}

int main(void) {
  printf("%ld",_565_main());
  return 0;
}
