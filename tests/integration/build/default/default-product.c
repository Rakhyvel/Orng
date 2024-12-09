/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    double _1;
};

/* Function forward definitions */
int64_t _571_main(void);


/* Function definitions */
int64_t _571_main(void){
    int64_t _571_t1;
    double _571_t2;
    struct struct0 _572_x;
    int64_t _571_t5;
    uint8_t _571_t7;
    int64_t _571_t4;
    double _571_t8;
    uint8_t _571_t10;
    int64_t _571_$retval;
    _571_t1 = 0;
    _571_t2 = 0e0;
    _572_x = (struct struct0) {_571_t1, _571_t2};
    _571_t5 = 0;
    _571_t7 = _572_x._0==_571_t5;
    if (_571_t7) {
        goto BB648;
    } else {
        goto BB655;
    }
BB648:
    _571_t8 = 0e0;
    _571_t10 = _572_x._1==_571_t8;
    if (_571_t10) {
        goto BB651;
    } else {
        goto BB655;
    }
BB655:
    _571_t4 = 0;
    goto BB654;
BB651:
    _571_t4 = 135;
    goto BB654;
BB654:
    _571_$retval = _571_t4;
    return _571_$retval;
}


int main(void) {
  printf("%ld",_571_main());
  return 0;
}
