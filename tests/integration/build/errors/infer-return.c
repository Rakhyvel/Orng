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
int64_t _614_main(void);
struct struct1 _620_f(void);


/* Function definitions */
int64_t _614_main(void){
    function0 _614_t1;
    struct struct1 _614_t2;
    uint64_t _614_t3;
    uint64_t _614_t4;
    uint8_t _614_t5;
    int64_t _614_$retval;
    uint64_t _614_t6;
    uint64_t _614_t7;
    uint8_t _614_t8;
    _614_t1 = _620_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:3:13:\n    match f() {\n           ^";
    _614_t2 = _614_t1();
    $line_idx--;
    _614_t3 = 0;
    _614_t4 = _614_t2.tag;
    _614_t5 = _614_t4==_614_t3;
    if (_614_t5) {
        goto BB721;
    } else {
        goto BB722;
    }
BB721:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB722:
    _614_t6 = 1;
    _614_t7 = _614_t2.tag;
    _614_t8 = _614_t7==_614_t6;
    if (_614_t8) {
        goto BB724;
    } else {
        goto BB728;
    }
BB724:
    _614_$retval = 238;
    return _614_$retval;
BB728:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:6:25:\n        _ => unreachable\n                       ^";
    $panic("reached unreachable code\n");
}

struct struct1 _620_f(void){
    struct struct1 _620_$retval;
    _620_$retval = (struct struct1) {.tag=1};
    return _620_$retval;
}


int main(void) {
  printf("%ld",_614_main());
  return 0;
}
