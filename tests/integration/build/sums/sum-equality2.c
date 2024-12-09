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
int64_t _1592_main(void);
struct struct1 _1597_f(void);


/* Function definitions */
int64_t _1592_main(void){
    function0 _1592_t1;
    struct struct1 _1592_t2;
    function0 _1592_t3;
    struct struct1 _1592_t4;
    uint64_t _1592_t7;
    uint64_t _1592_t8;
    uint8_t _1592_t6;
    int64_t _1592_t0;
    int64_t _1592_$retval;
    _1592_t1 = (function0) _1597_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1592_t2 = _1592_t1();
    $line_idx--;
    _1592_t3 = (function0) _1597_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1592_t4 = _1592_t3();
    $line_idx--;
    _1592_t7 = _1592_t2.tag;
    _1592_t8 = _1592_t4.tag;
    _1592_t6 = _1592_t7==_1592_t8;
    if (_1592_t6) {
        goto BB1826;
    } else {
        goto BB1830;
    }
BB1826:
    _1592_t0 = 212;
    goto BB1829;
BB1830:
    _1592_t0 = -1;
    goto BB1829;
BB1829:
    _1592_$retval = _1592_t0;
    return _1592_$retval;
}

struct struct1 _1597_f(void){
    struct struct1 _1597_$retval;
    _1597_$retval = (struct struct1) {.tag=1};
    return _1597_$retval;
}


int main(void) {
  printf("%ld",_1592_main());
  return 0;
}
