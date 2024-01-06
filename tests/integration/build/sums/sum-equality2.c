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
int64_t _1470_main(void);
struct struct1 _1475_f(void);

/* Function definitions */
int64_t _1470_main(void){
    function0 _1470_t1;
    struct struct1 _1470_t2;
    function0 _1470_t3;
    struct struct1 _1470_t4;
    uint64_t _1470_t7;
    uint64_t _1470_t8;
    uint8_t _1470_t6;
    int64_t _1470_t0;
    int64_t _1470_$retval;
    _1470_t1 = _1475_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1470_t2 = _1470_t1();
    $line_idx--;
    _1470_t3 = _1475_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1470_t4 = _1470_t3();
    $line_idx--;
    _1470_t7 = _1470_t2.tag;
    _1470_t8 = _1470_t4.tag;
    _1470_t6 = _1470_t7==_1470_t8;
    if (_1470_t6) {
        goto BB1734;
    } else {
        goto BB1738;
    }
BB1734:
    _1470_t0 = 212;
    goto BB1737;
BB1738:
    _1470_t0 = -1;
    goto BB1737;
BB1737:
    _1470_$retval = _1470_t0;
    return _1470_$retval;
}

struct struct1 _1475_f(void){
    struct struct1 _1475_$retval;
    _1475_$retval = (struct struct1) {.tag=1};
    return _1475_$retval;
}

int main(void) {
  printf("%ld",_1470_main());
  return 0;
}
