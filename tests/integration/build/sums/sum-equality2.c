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
int64_t _1607_main(void);
struct struct1 _1612_f(void);


/* Function definitions */
int64_t _1607_main(void){
    function0 _1607_t1;
    struct struct1 _1607_t2;
    function0 _1607_t3;
    struct struct1 _1607_t4;
    uint64_t _1607_t7;
    uint64_t _1607_t8;
    uint8_t _1607_t6;
    int64_t _1607_t0;
    int64_t _1607_$retval;
    _1607_t1 = (function0) _1612_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1607_t2 = _1607_t1();
    $line_idx--;
    _1607_t3 = (function0) _1612_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1607_t4 = _1607_t3();
    $line_idx--;
    _1607_t7 = _1607_t2.tag;
    _1607_t8 = _1607_t4.tag;
    _1607_t6 = _1607_t7==_1607_t8;
    if (_1607_t6) {
        goto BB1842;
    } else {
        goto BB1846;
    }
BB1842:
    _1607_t0 = 212;
    goto BB1845;
BB1846:
    _1607_t0 = -1;
    goto BB1845;
BB1845:
    _1607_$retval = _1607_t0;
    return _1607_$retval;
}

struct struct1 _1612_f(void){
    struct struct1 _1612_$retval;
    _1612_$retval = (struct struct1) {.tag=1};
    return _1612_$retval;
}


int main(void) {
  printf("%ld",_1607_main());
  return 0;
}
