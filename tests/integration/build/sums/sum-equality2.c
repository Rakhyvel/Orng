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
int64_t _1486_main(void);
struct struct1 _1491_f(void);


/* Function definitions */
int64_t _1486_main(void){
    function0 _1486_t1;
    struct struct1 _1486_t2;
    function0 _1486_t3;
    struct struct1 _1486_t4;
    uint64_t _1486_t7;
    uint64_t _1486_t8;
    uint8_t _1486_t6;
    int64_t _1486_t0;
    int64_t _1486_$retval;
    _1486_t1 = (function0) _1491_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1486_t2 = _1486_t1();
    $line_idx--;
    _1486_t3 = (function0) _1491_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1486_t4 = _1486_t3();
    $line_idx--;
    _1486_t7 = _1486_t2.tag;
    _1486_t8 = _1486_t4.tag;
    _1486_t6 = _1486_t7==_1486_t8;
    if (_1486_t6) {
        goto BB1717;
    } else {
        goto BB1721;
    }
BB1717:
    _1486_t0 = 212;
    goto BB1720;
BB1721:
    _1486_t0 = -1;
    goto BB1720;
BB1720:
    _1486_$retval = _1486_t0;
    return _1486_$retval;
}

struct struct1 _1491_f(void){
    struct struct1 _1491_$retval;
    _1491_$retval = (struct struct1) {.tag=1};
    return _1491_$retval;
}


int main(void) {
  printf("%ld",_1486_main());
  return 0;
}
