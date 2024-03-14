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
int64_t _1520_main(void);
struct struct1 _1525_f(void);


/* Function definitions */
int64_t _1520_main(void){
    function0 _1520_t1;
    struct struct1 _1520_t2;
    function0 _1520_t3;
    struct struct1 _1520_t4;
    uint64_t _1520_t7;
    uint64_t _1520_t8;
    uint8_t _1520_t6;
    int64_t _1520_t0;
    int64_t _1520_$retval;
    _1520_t1 = (function0) _1525_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1520_t2 = _1520_t1();
    $line_idx--;
    _1520_t3 = (function0) _1525_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1520_t4 = _1520_t3();
    $line_idx--;
    _1520_t7 = _1520_t2.tag;
    _1520_t8 = _1520_t4.tag;
    _1520_t6 = _1520_t7==_1520_t8;
    if (_1520_t6) {
        goto BB1770;
    } else {
        goto BB1774;
    }
BB1770:
    _1520_t0 = 212;
    goto BB1773;
BB1774:
    _1520_t0 = -1;
    goto BB1773;
BB1773:
    _1520_$retval = _1520_t0;
    return _1520_$retval;
}

struct struct1 _1525_f(void){
    struct struct1 _1525_$retval;
    _1525_$retval = (struct struct1) {.tag=1};
    return _1525_$retval;
}


int main(void) {
  printf("%ld",_1520_main());
  return 0;
}
