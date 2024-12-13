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
    int64_t* _0;
    int64_t* _1;
};

typedef uint8_t(*function0)(int64_t*, int64_t*);

/* Function forward definitions */
int64_t _654_main(void);
uint8_t _659_addr_equal(int64_t* _659_x, int64_t* _659_y);


/* Function definitions */
int64_t _654_main(void){
    int64_t _655_x;
    int64_t _655_y;
    function0 _654_t5;
    int64_t* _654_t7;
    int64_t* _654_t8;
    uint8_t _654_t6;
    function0 _654_t9;
    int64_t* _654_t11;
    int64_t* _654_t12;
    uint8_t _654_t10;
    int64_t _654_t4;
    int64_t _654_$retval;
    _655_x = 4;
    _655_y = 4;
    _654_t5 = (function0) _659_addr_equal;
    _654_t7 = &_655_x;
    _654_t8 = &_655_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _654_t6 = _654_t5(_654_t7, _654_t8);
    $line_idx--;
    if (_654_t6) {
        goto BB769;
    } else {
        goto BB774;
    }
BB769:
    _654_t9 = (function0) _659_addr_equal;
    _654_t11 = &_655_x;
    _654_t12 = &_655_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _654_t10 = _654_t9(_654_t11, _654_t12);
    $line_idx--;
    if (_654_t10) {
        goto BB774;
    } else {
        goto BB770;
    }
BB774:
    _654_t4 = -3;
    goto BB773;
BB770:
    _654_t4 = 236;
    goto BB773;
BB773:
    _654_$retval = _654_t4;
    return _654_$retval;
}

uint8_t _659_addr_equal(int64_t* _659_x, int64_t* _659_y){
    uint8_t _659_t1;
    uint8_t _659_t0;
    uint8_t _659_$retval;
    _659_t1 = _659_x==_659_y;
    if (_659_t1) {
        goto BB764;
    } else {
        goto BB767;
    }
BB764:
    _659_t0 = 1;
    goto BB766;
BB767:
    _659_t0 = 0;
    goto BB766;
BB766:
    _659_$retval = _659_t0;
    return _659_$retval;
}


int main(void) {
  printf("%ld",_654_main());
  return 0;
}
