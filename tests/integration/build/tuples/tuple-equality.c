/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;
struct struct3;

/* Typedefs */
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
int64_t _1567_main(void);
uint8_t _1572_f(struct struct1 _1572_x, struct struct1 _1572_y);

/* Function definitions */
int64_t _1567_main(void){
    int64_t _1567_t1;
    int64_t _1567_t3;
    double _1567_t4;
    struct struct0 _1567_t2;
    uint32_t _1567_t5;
    struct struct1 _1568_x;
    int64_t _1567_t7;
    int64_t _1567_t9;
    double _1567_t10;
    struct struct0 _1567_t8;
    uint32_t _1567_t11;
    struct struct1 _1568_y;
    function2 _1567_t13;
    uint8_t _1567_t14;
    int64_t _1567_t12;
    int64_t _1567_$retval;
    _1567_t1 = 1;
    _1567_t3 = 2;
    _1567_t4 = 3.4e+00;
    _1567_t2 = (struct struct0) {_1567_t3, _1567_t4};
    _1567_t5 = 114;
    _1568_x = (struct struct1) {_1567_t1, _1567_t2, _1567_t5};
    _1567_t7 = 1;
    _1567_t9 = 2;
    _1567_t10 = 3.4e+00;
    _1567_t8 = (struct struct0) {_1567_t9, _1567_t10};
    _1567_t11 = 114;
    _1568_y = (struct struct1) {_1567_t7, _1567_t8, _1567_t11};
    _1567_t13 = _1572_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1567_t14 = _1567_t13(_1568_x, _1568_y);
    $line_idx--;
    if (_1567_t14) {
        goto BB1825;
    } else {
        goto BB1829;
    }
BB1825:
    _1567_t12 = 238;
    goto BB1828;
BB1829:
    _1567_t12 = 832;
    goto BB1828;
BB1828:
    _1567_$retval = _1567_t12;
    return _1567_$retval;
}

uint8_t _1572_f(struct struct1 _1572_x, struct struct1 _1572_y){
    uint8_t _1572_t2;
    uint8_t _1572_t4;
    uint8_t _1572_t5;
    uint8_t _1572_t6;
    uint8_t _1572_t0;
    uint8_t _1572_$retval;
    _1572_t2 = _1572_x._0==_1572_y._0;
    if (_1572_t2) {
        goto BB1817;
    } else {
        goto BB1823;
    }
BB1817:
    _1572_t4 = _1572_x._1._0==_1572_y._1._0;
    if (_1572_t4) {
        goto BB1818;
    } else {
        goto BB1823;
    }
BB1823:
    _1572_t0 = 0;
    goto BB1822;
BB1818:
    _1572_t5 = _1572_x._1._1==_1572_y._1._1;
    if (_1572_t5) {
        goto BB1819;
    } else {
        goto BB1823;
    }
BB1822:
    _1572_$retval = _1572_t0;
    return _1572_$retval;
BB1819:
    _1572_t6 = _1572_x._2==_1572_y._2;
    if (_1572_t6) {
        goto BB1820;
    } else {
        goto BB1823;
    }
BB1820:
    _1572_t0 = 1;
    goto BB1822;
}

int main(void) {
  printf("%ld",_1567_main());
  return 0;
}
