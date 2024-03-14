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
int64_t _567_main(void);


/* Function definitions */
int64_t _567_main(void){
    int64_t _567_t1;
    double _567_t2;
    struct struct0 _568_x;
    int64_t _567_t5;
    uint8_t _567_t7;
    int64_t _567_t4;
    double _567_t8;
    uint8_t _567_t10;
    int64_t _567_$retval;
    _567_t1 = 0;
    _567_t2 = 0.0e+00;
    _568_x = (struct struct0) {_567_t1, _567_t2};
    _567_t5 = 0;
    _567_t7 = _568_x._0==_567_t5;
    if (_567_t7) {
        goto BB648;
    } else {
        goto BB655;
    }
BB648:
    _567_t8 = 0.0e+00;
    _567_t10 = _568_x._1==_567_t8;
    if (_567_t10) {
        goto BB651;
    } else {
        goto BB655;
    }
BB655:
    _567_t4 = 0;
    goto BB654;
BB651:
    _567_t4 = 135;
    goto BB654;
BB654:
    _567_$retval = _567_t4;
    return _567_$retval;
}


int main(void) {
  printf("%ld",_567_main());
  return 0;
}
