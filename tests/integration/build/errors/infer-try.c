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
    };
};

typedef struct struct1(*function0)(void);

/* Function forward definitions */
int64_t _596_main(void);
struct struct1 _602_f(void);
struct struct1 _604_g(void);

/* Function definitions */
int64_t _596_main(void){
    function0 _596_t1;
    struct struct1 _596_t2;
    uint64_t _596_t3;
    uint64_t _596_t4;
    uint8_t _596_t5;
    int64_t _596_$retval;
    uint64_t _596_t6;
    uint64_t _596_t7;
    uint8_t _596_t8;
    _596_t1 = _602_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _596_t2 = _596_t1();
    $line_idx--;
    _596_t3 = 0;
    _596_t4 = _596_t2.tag;
    _596_t5 = _596_t4==_596_t3;
    if (_596_t5) {
        goto BB716;
    } else {
        goto BB717;
    }
BB716:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB717:
    _596_t6 = 1;
    _596_t7 = _596_t2.tag;
    _596_t8 = _596_t7==_596_t6;
    if (_596_t8) {
        goto BB719;
    } else {
        goto BB723;
    }
BB719:
    _596_$retval = 239;
    return _596_$retval;
BB723:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:25:\n        _ => unreachable\n                       ^";
    $panic("reached unreachable code\n");
}

struct struct1 _602_f(void){
    function0 _602_t0;
    struct struct1 _602_t1;
    uint64_t _602_t2;
    struct struct1 _602_$retval;
    _602_t0 = _604_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:15:\n    .ok(try g())\n             ^";
    _602_t1 = _602_t0();
    $line_idx--;
    _602_t2 = _602_t1.tag;
    if (_602_t2) {
        goto BB709;
    } else {
        goto BB711;
    }
BB709:
    _602_$retval = _602_t1;
    return _602_$retval;
BB711:
    _602_$retval = (struct struct1) {.tag=0, ._0=(_602_t1._0)};
    return _602_$retval;
}

struct struct1 _604_g(void){
    struct struct1 _604_$retval;
    _604_$retval = (struct struct1) {.tag=1};
    return _604_$retval;
}

int main(void) {
  printf("%ld",_596_main());
  return 0;
}
