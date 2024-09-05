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
int64_t _1550_main(void);
struct struct1 _1555_f(void);


/* Function definitions */
int64_t _1550_main(void){
    function0 _1550_t1;
    struct struct1 _1550_t2;
    function0 _1550_t3;
    struct struct1 _1550_t4;
    uint64_t _1550_t7;
    uint64_t _1550_t8;
    uint8_t _1550_t6;
    int64_t _1550_t0;
    int64_t _1550_$retval;
    _1550_t1 = (function0) _1555_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1550_t2 = _1550_t1();
    $line_idx--;
    _1550_t3 = (function0) _1555_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1550_t4 = _1550_t3();
    $line_idx--;
    _1550_t7 = _1550_t2.tag;
    _1550_t8 = _1550_t4.tag;
    _1550_t6 = _1550_t7==_1550_t8;
    if (_1550_t6) {
        goto BB1785;
    } else {
        goto BB1789;
    }
BB1785:
    _1550_t0 = 212;
    goto BB1788;
BB1789:
    _1550_t0 = -1;
    goto BB1788;
BB1788:
    _1550_$retval = _1550_t0;
    return _1550_$retval;
}

struct struct1 _1555_f(void){
    struct struct1 _1555_$retval;
    _1555_$retval = (struct struct1) {.tag=1};
    return _1555_$retval;
}


int main(void) {
  printf("%ld",_1550_main());
  return 0;
}
