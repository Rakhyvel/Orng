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
int64_t _1485_main(void);
struct struct1 _1490_f(void);

/* Function definitions */
int64_t _1485_main(void){
    function0 _1485_t1;
    struct struct1 _1485_t2;
    function0 _1485_t3;
    struct struct1 _1485_t4;
    uint64_t _1485_t7;
    uint64_t _1485_t8;
    uint8_t _1485_t6;
    int64_t _1485_t0;
    int64_t _1485_$retval;
    _1485_t1 = _1490_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1485_t2 = _1485_t1();
    $line_idx--;
    _1485_t3 = _1490_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1485_t4 = _1485_t3();
    $line_idx--;
    _1485_t7 = _1485_t2.tag;
    _1485_t8 = _1485_t4.tag;
    _1485_t6 = _1485_t7==_1485_t8;
    if (_1485_t6) {
        goto BB1750;
    } else {
        goto BB1754;
    }
BB1750:
    _1485_t0 = 212;
    goto BB1753;
BB1754:
    _1485_t0 = -1;
    goto BB1753;
BB1753:
    _1485_$retval = _1485_t0;
    return _1485_$retval;
}

struct struct1 _1490_f(void){
    struct struct1 _1490_$retval;
    _1490_$retval = (struct struct1) {.tag=1};
    return _1490_$retval;
}

int main(void) {
  printf("%ld",_1485_main());
  return 0;
}
