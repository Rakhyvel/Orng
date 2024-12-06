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
int64_t _1579_main(void);
struct struct1 _1584_f(void);


/* Function definitions */
int64_t _1579_main(void){
    function0 _1579_t1;
    struct struct1 _1579_t2;
    function0 _1579_t3;
    struct struct1 _1579_t4;
    uint64_t _1579_t7;
    uint64_t _1579_t8;
    uint8_t _1579_t6;
    int64_t _1579_t0;
    int64_t _1579_$retval;
    _1579_t1 = (function0) _1584_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1579_t2 = _1579_t1();
    $line_idx--;
    _1579_t3 = (function0) _1584_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1579_t4 = _1579_t3();
    $line_idx--;
    _1579_t7 = _1579_t2.tag;
    _1579_t8 = _1579_t4.tag;
    _1579_t6 = _1579_t7==_1579_t8;
    if (_1579_t6) {
        goto BB1813;
    } else {
        goto BB1817;
    }
BB1813:
    _1579_t0 = 212;
    goto BB1816;
BB1817:
    _1579_t0 = -1;
    goto BB1816;
BB1816:
    _1579_$retval = _1579_t0;
    return _1579_$retval;
}

struct struct1 _1584_f(void){
    struct struct1 _1584_$retval;
    _1584_$retval = (struct struct1) {.tag=1};
    return _1584_$retval;
}


int main(void) {
  printf("%ld",_1579_main());
  return 0;
}
