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
int64_t _1495_main(void);
struct struct1 _1500_f(void);


/* Function definitions */
int64_t _1495_main(void){
    function0 _1495_t1;
    struct struct1 _1495_t2;
    function0 _1495_t3;
    struct struct1 _1495_t4;
    uint64_t _1495_t7;
    uint64_t _1495_t8;
    uint8_t _1495_t6;
    int64_t _1495_t0;
    int64_t _1495_$retval;
    _1495_t1 = (function0) _1500_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1495_t2 = _1495_t1();
    $line_idx--;
    _1495_t3 = (function0) _1500_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1495_t4 = _1495_t3();
    $line_idx--;
    _1495_t7 = _1495_t2.tag;
    _1495_t8 = _1495_t4.tag;
    _1495_t6 = _1495_t7==_1495_t8;
    if (_1495_t6) {
        goto BB1723;
    } else {
        goto BB1727;
    }
BB1723:
    _1495_t0 = 212;
    goto BB1726;
BB1727:
    _1495_t0 = -1;
    goto BB1726;
BB1726:
    _1495_$retval = _1495_t0;
    return _1495_$retval;
}

struct struct1 _1500_f(void){
    struct struct1 _1500_$retval;
    _1500_$retval = (struct struct1) {.tag=1};
    return _1500_$retval;
}


int main(void) {
  printf("%ld",_1495_main());
  return 0;
}
