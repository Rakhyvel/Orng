/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;

/* Typedefs */
struct struct1 {
    uint64_t tag;
    union {
        int64_t _0;
        int64_t _1;
    };
};

typedef struct struct1(*function0)(uint8_t);

/* Function forward definitions */
int64_t _574_main(void);
struct struct1 _581_f(uint8_t _581_give_int);

/* Function definitions */
int64_t _574_main(void){
    function0 _574_t1;
    uint8_t _574_t3;
    struct struct1 _574_t2;
    uint64_t _574_t4;
    uint64_t _574_t5;
    uint8_t _574_t6;
    uint64_t _574_t10;
    uint64_t _574_t11;
    uint8_t _574_t12;
    uint64_t _574_t7;
    uint64_t _574_t8;
    uint8_t _574_t9;
    int64_t _574_$retval;
    _574_t1 = _581_f;
    _574_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:3:13:\n    match f(true) {\n           ^";
    _574_t2 = _574_t1(_574_t3);
    $line_idx--;
    _574_t4 = 0;
    _574_t5 = _574_t2.tag;
    _574_t6 = _574_t5==_574_t4;
    if (_574_t6) {
        goto BB694;
    } else {
        goto BB695;
    }
BB694:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB695:
    _574_t7 = 2;
    _574_t8 = _574_t2.tag;
    _574_t9 = _574_t8==_574_t7;
    if (_574_t9) {
        goto BB697;
    } else {
        goto BB698;
    }
BB697:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:5:32:\n        .error_1 => unreachable\n                              ^";
    $panic("reached unreachable code\n");
BB698:
    _574_t10 = 1;
    _574_t11 = _574_t2.tag;
    _574_t12 = _574_t11==_574_t10;
    if (_574_t12) {
        goto BB700;
    } else {
        goto BB704;
    }
BB700:
    _574_$retval = _574_t2._1;
    return _574_$retval;
BB704:
    $lines[$line_idx++] = "tests/integration/errors/infer-inject.orng:7:25:\n        _ => unreachable\n                       ^";
    $panic("reached unreachable code\n");
}

struct struct1 _581_f(uint8_t _581_give_int){
    int64_t _581_t1;
    struct struct1 _581_t0;
    struct struct1 _581_$retval;
    if (_581_give_int) {
        goto BB685;
    } else {
        goto BB689;
    }
BB685:
    _581_t1 = 240;
    _581_t0 = (struct struct1) {.tag=1, ._1=_581_t1};
    goto BB688;
BB689:
    _581_t0 = (struct struct1) {.tag=2};
    goto BB688;
BB688:
    _581_$retval = _581_t0;
    return _581_$retval;
}

int main(void) {
  printf("%ld",_574_main());
  return 0;
}
