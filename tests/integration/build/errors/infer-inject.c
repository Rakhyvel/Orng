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
int64_t _601_main(void);
struct struct1 _608_f(uint8_t _608_give_int);


/* Function definitions */
int64_t _601_main(void){
    function0 _601_t1;
    uint8_t _601_t3;
    struct struct1 _601_t2;
    uint64_t _601_t4;
    uint64_t _601_t5;
    uint8_t _601_t6;
    uint64_t _601_t10;
    uint64_t _601_t11;
    uint8_t _601_t12;
    uint64_t _601_t7;
    uint64_t _601_t8;
    uint8_t _601_t9;
    int64_t _601_$retval;
    _601_t1 = (function0) _608_f;
    _601_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:3:13:\n    match f(true) {\n           ^";
    _601_t2 = _601_t1(_601_t3);
    $line_idx--;
    _601_t4 = 0;
    _601_t5 = _601_t2.tag;
    _601_t6 = _601_t5==_601_t4;
    if (_601_t6) {
        goto BB699;
    } else {
        goto BB700;
    }
BB699:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB700:
    _601_t7 = 2;
    _601_t8 = _601_t2.tag;
    _601_t9 = _601_t8==_601_t7;
    if (_601_t9) {
        goto BB702;
    } else {
        goto BB703;
    }
BB702:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:5:32:\n        .error_1 => unreachable\n                              ^";
    $panic("reached unreachable code\n");
BB703:
    _601_t10 = 1;
    _601_t11 = _601_t2.tag;
    _601_t12 = _601_t11==_601_t10;
    if (_601_t12) {
        goto BB705;
    } else {
        goto BB709;
    }
BB705:
    _601_$retval = _601_t2._1;
    return _601_$retval;
BB709:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:7:25:\n        _ => unreachable\n                       ^";
    $panic("reached unreachable code\n");
}

struct struct1 _608_f(uint8_t _608_give_int){
    int64_t _608_t1;
    struct struct1 _608_t0;
    struct struct1 _608_$retval;
    if (_608_give_int) {
        goto BB690;
    } else {
        goto BB694;
    }
BB690:
    _608_t1 = 240;
    _608_t0 = (struct struct1) {.tag=1, ._1=_608_t1};
    goto BB693;
BB694:
    _608_t0 = (struct struct1) {.tag=2};
    goto BB693;
BB693:
    _608_$retval = _608_t0;
    return _608_$retval;
}


int main(void) {
  printf("%ld",_601_main());
  return 0;
}
