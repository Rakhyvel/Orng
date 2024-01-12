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
int64_t _1480_main(void);
struct struct1 _1485_f(void);

/* Function definitions */
int64_t _1480_main(void){
    function0 _1480_t1;
    struct struct1 _1480_t2;
    function0 _1480_t3;
    struct struct1 _1480_t4;
    uint64_t _1480_t7;
    uint64_t _1480_t8;
    uint8_t _1480_t6;
    int64_t _1480_t0;
    int64_t _1480_$retval;
    _1480_t1 = _1485_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1480_t2 = _1480_t1();
    $line_idx--;
    _1480_t3 = _1485_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1480_t4 = _1480_t3();
    $line_idx--;
    _1480_t7 = _1480_t2.tag;
    _1480_t8 = _1480_t4.tag;
    _1480_t6 = _1480_t7==_1480_t8;
    if (_1480_t6) {
        goto BB1746;
    } else {
        goto BB1750;
    }
BB1746:
    _1480_t0 = 212;
    goto BB1749;
BB1750:
    _1480_t0 = -1;
    goto BB1749;
BB1749:
    _1480_$retval = _1480_t0;
    return _1480_$retval;
}

struct struct1 _1485_f(void){
    struct struct1 _1485_$retval;
    _1485_$retval = (struct struct1) {.tag=1};
    return _1485_$retval;
}

int main(void) {
  printf("%ld",_1480_main());
  return 0;
}
