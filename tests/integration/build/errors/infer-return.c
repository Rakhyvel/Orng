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
int64_t _587_main(void);
struct struct1 _593_f(void);

/* Function definitions */
int64_t _587_main(void){
    function0 _587_t1;
    struct struct1 _587_t2;
    uint64_t _587_t3;
    uint64_t _587_t4;
    uint8_t _587_t5;
    int64_t _587_$retval;
    uint64_t _587_t6;
    uint64_t _587_t7;
    uint8_t _587_t8;
    _587_t1 = _593_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:3:13:\n    match f() {\n           ^";
    _587_t2 = _587_t1();
    $line_idx--;
    _587_t3 = 0;
    _587_t4 = _587_t2.tag;
    _587_t5 = _587_t4==_587_t3;
    if (_587_t5) {
        goto BB709;
    } else {
        goto BB710;
    }
BB709:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB710:
    _587_t6 = 1;
    _587_t7 = _587_t2.tag;
    _587_t8 = _587_t7==_587_t6;
    if (_587_t8) {
        goto BB712;
    } else {
        goto BB716;
    }
BB712:
    _587_$retval = 238;
    return _587_$retval;
BB716:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:6:25:\n        _ => unreachable\n                       ^";
    $panic("reached unreachable code\n");
}

struct struct1 _593_f(void){
    struct struct1 _593_$retval;
    _593_$retval = (struct struct1) {.tag=1};
    return _593_$retval;
}

int main(void) {
  printf("%ld",_587_main());
  return 0;
}
