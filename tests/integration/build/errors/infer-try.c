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
    };
};

typedef struct struct1(*function0)(void);

/* Function forward definitions */
int64_t _47_main(void);
struct struct1 _53_f(void);
struct struct1 _55_g(void);


/* Function definitions */
int64_t _47_main(void){
    function0 _47_t1;
    struct struct1 _47_t2;
    uint64_t _47_t3;
    uint64_t _47_t4;
    uint8_t _47_t5;
    int64_t _47_$retval;
    uint64_t _47_t6;
    uint64_t _47_t7;
    uint8_t _47_t8;
    _47_t1 = (function0) _53_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _47_t2 = _47_t1();
    $line_idx--;
    _47_t3 = 0;
    _47_t4 = _47_t2.tag;
    _47_t5 = _47_t4==_47_t3;
    if (_47_t5) {
        goto BB71;
    } else {
        goto BB72;
    }
BB71:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB72:
    _47_t6 = 1;
    _47_t7 = _47_t2.tag;
    _47_t8 = _47_t7==_47_t6;
    if (_47_t8) {
        goto BB74;
    } else {
        goto BB78;
    }
BB74:
    _47_$retval = 239;
    return _47_$retval;
BB78:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:25:\n        _ => unreachable\n                       ^";
    $panic("reached unreachable code\n");
}

struct struct1 _53_f(void){
    function0 _53_t0;
    struct struct1 _53_t1;
    uint64_t _53_t2;
    struct struct1 _53_$retval;
    _53_t0 = (function0) _55_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:15:\n    .ok(try g())\n             ^";
    _53_t1 = _53_t0();
    $line_idx--;
    _53_t2 = _53_t1.tag;
    if (_53_t2) {
        goto BB64;
    } else {
        goto BB66;
    }
BB64:
    _53_$retval = _53_t1;
    return _53_$retval;
BB66:
    _53_$retval = (struct struct1) {.tag=0, ._0=(_53_t1._0)};
    return _53_$retval;
}

struct struct1 _55_g(void){
    struct struct1 _55_$retval;
    _55_$retval = (struct struct1) {.tag=1};
    return _55_$retval;
}


int main(void) {
  printf("%ld",_47_main());
  return 0;
}
