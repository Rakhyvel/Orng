/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;
struct struct3;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    double _1;
};

struct struct1 {
    int64_t _0;
    struct struct0 _1;
    uint32_t _2;
};

struct struct3 {
    struct struct1 _0;
    struct struct1 _1;
};

typedef uint8_t(*function2)(struct struct1, struct struct1);

/* Function forward definitions */
int64_t _1941_main(void);
uint8_t _1946_f(struct struct1 _1946_x, struct struct1 _1946_y);


/* Function definitions */
int64_t _1941_main(void){
    int64_t _1941_t1;
    int64_t _1941_t3;
    double _1941_t4;
    struct struct0 _1941_t2;
    uint32_t _1941_t5;
    struct struct1 _1942_x;
    int64_t _1941_t8;
    int64_t _1941_t10;
    double _1941_t11;
    struct struct0 _1941_t9;
    uint32_t _1941_t12;
    struct struct1 _1942_y;
    function2 _1941_t15;
    uint8_t _1941_t16;
    int64_t _1941_t14;
    int64_t _1941_$retval;
    _1941_t1 = 1;
    _1941_t3 = 2;
    _1941_t4 = 3.4e0;
    _1941_t2 = (struct struct0) {_1941_t3, _1941_t4};
    _1941_t5 = 114;
    _1942_x = (struct struct1) {_1941_t1, _1941_t2, _1941_t5};
    _1941_t8 = 1;
    _1941_t10 = 2;
    _1941_t11 = 3.4e0;
    _1941_t9 = (struct struct0) {_1941_t10, _1941_t11};
    _1941_t12 = 114;
    _1942_y = (struct struct1) {_1941_t8, _1941_t9, _1941_t12};
    _1941_t15 = (function2) _1946_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1941_t16 = _1941_t15(_1942_x, _1942_y);
    $line_idx--;
    if (_1941_t16) {
        goto BB2100;
    } else {
        goto BB2104;
    }
BB2100:
    _1941_t14 = 238;
    goto BB2103;
BB2104:
    _1941_t14 = 832;
    goto BB2103;
BB2103:
    _1941_$retval = _1941_t14;
    return _1941_$retval;
}

uint8_t _1946_f(struct struct1 _1946_x, struct struct1 _1946_y){
    uint8_t _1946_t2;
    uint8_t _1946_t4;
    uint8_t _1946_t5;
    uint8_t _1946_t6;
    uint8_t _1946_t0;
    uint8_t _1946_$retval;
    _1946_t2 = _1946_x._0==_1946_y._0;
    if (_1946_t2) {
        goto BB2092;
    } else {
        goto BB2098;
    }
BB2092:
    _1946_t4 = _1946_x._1._0==_1946_y._1._0;
    if (_1946_t4) {
        goto BB2093;
    } else {
        goto BB2098;
    }
BB2098:
    _1946_t0 = 0;
    goto BB2097;
BB2093:
    _1946_t5 = _1946_x._1._1==_1946_y._1._1;
    if (_1946_t5) {
        goto BB2094;
    } else {
        goto BB2098;
    }
BB2097:
    _1946_$retval = _1946_t0;
    return _1946_$retval;
BB2094:
    _1946_t6 = _1946_x._2==_1946_y._2;
    if (_1946_t6) {
        goto BB2095;
    } else {
        goto BB2098;
    }
BB2095:
    _1946_t0 = 1;
    goto BB2097;
}


int main(void) {
  printf("%ld",_1941_main());
  return 0;
}
