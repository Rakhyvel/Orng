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
int64_t _38_main(void);
struct struct1 _44_f(void);


/* Function definitions */
int64_t _38_main(void){
    function0 _38_t1;
    struct struct1 _38_t2;
    uint64_t _38_t3;
    uint64_t _38_t4;
    uint8_t _38_t5;
    int64_t _38_$retval;
    uint64_t _38_t6;
    uint64_t _38_t7;
    uint8_t _38_t8;
    _38_t1 = (function0) _44_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:3:13:\n    match f() {\n           ^";
    _38_t2 = _38_t1();
    $line_idx--;
    _38_t3 = 0;
    _38_t4 = _38_t2.tag;
    _38_t5 = _38_t4==_38_t3;
    if (_38_t5) {
        goto BB54;
    } else {
        goto BB55;
    }
BB54:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB55:
    _38_t6 = 1;
    _38_t7 = _38_t2.tag;
    _38_t8 = _38_t7==_38_t6;
    if (_38_t8) {
        goto BB57;
    } else {
        goto BB61;
    }
BB57:
    _38_$retval = 238;
    return _38_$retval;
BB61:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:6:25:\n        _ => unreachable\n                       ^";
    $panic("reached unreachable code\n");
}

struct struct1 _44_f(void){
    struct struct1 _44_$retval;
    _44_$retval = (struct struct1) {.tag=1};
    return _44_$retval;
}


int main(void) {
  printf("%ld",_38_main());
  return 0;
}
