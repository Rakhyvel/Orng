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
int64_t _1573_main(void);
struct struct1 _1578_f(void);


/* Function definitions */
int64_t _1573_main(void){
    function0 _1573_t1;
    struct struct1 _1573_t2;
    function0 _1573_t3;
    struct struct1 _1573_t4;
    uint64_t _1573_t7;
    uint64_t _1573_t8;
    uint8_t _1573_t6;
    int64_t _1573_t0;
    int64_t _1573_$retval;
    _1573_t1 = (function0) _1578_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1573_t2 = _1573_t1();
    $line_idx--;
    _1573_t3 = (function0) _1578_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1573_t4 = _1573_t3();
    $line_idx--;
    _1573_t7 = _1573_t2.tag;
    _1573_t8 = _1573_t4.tag;
    _1573_t6 = _1573_t7==_1573_t8;
    if (_1573_t6) {
        goto BB1804;
    } else {
        goto BB1808;
    }
BB1804:
    _1573_t0 = 212;
    goto BB1807;
BB1808:
    _1573_t0 = -1;
    goto BB1807;
BB1807:
    _1573_$retval = _1573_t0;
    return _1573_$retval;
}

struct struct1 _1578_f(void){
    struct struct1 _1578_$retval;
    _1578_$retval = (struct struct1) {.tag=1};
    return _1578_$retval;
}


int main(void) {
  printf("%ld",_1573_main());
  return 0;
}
