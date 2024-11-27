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
int64_t _1563_main(void);
struct struct1 _1568_f(void);


/* Function definitions */
int64_t _1563_main(void){
    function0 _1563_t1;
    struct struct1 _1563_t2;
    function0 _1563_t3;
    struct struct1 _1563_t4;
    uint64_t _1563_t7;
    uint64_t _1563_t8;
    uint8_t _1563_t6;
    int64_t _1563_t0;
    int64_t _1563_$retval;
    _1563_t1 = (function0) _1568_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1563_t2 = _1563_t1();
    $line_idx--;
    _1563_t3 = (function0) _1568_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1563_t4 = _1563_t3();
    $line_idx--;
    _1563_t7 = _1563_t2.tag;
    _1563_t8 = _1563_t4.tag;
    _1563_t6 = _1563_t7==_1563_t8;
    if (_1563_t6) {
        goto BB1796;
    } else {
        goto BB1800;
    }
BB1796:
    _1563_t0 = 212;
    goto BB1799;
BB1800:
    _1563_t0 = -1;
    goto BB1799;
BB1799:
    _1563_$retval = _1563_t0;
    return _1563_$retval;
}

struct struct1 _1568_f(void){
    struct struct1 _1568_$retval;
    _1568_$retval = (struct struct1) {.tag=1};
    return _1568_$retval;
}


int main(void) {
  printf("%ld",_1563_main());
  return 0;
}
