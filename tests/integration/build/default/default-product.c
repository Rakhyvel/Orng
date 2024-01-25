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
    int64_t _567_t4;
    uint8_t _567_t6;
    int64_t _567_t3;
    double _567_t7;
    uint8_t _567_t9;
    int64_t _567_$retval;
    _567_t1 = 0;
    _567_t2 = 0.0e+00;
    _568_x = (struct struct0) {_567_t1, _567_t2};
    _567_t4 = 0;
    _567_t6 = _568_x._0==_567_t4;
    if (_567_t6) {
        goto BB655;
    } else {
        goto BB662;
    }
BB655:
    _567_t7 = 0.0e+00;
    _567_t9 = _568_x._1==_567_t7;
    if (_567_t9) {
        goto BB658;
    } else {
        goto BB662;
    }
BB662:
    _567_t3 = 0;
    goto BB661;
BB658:
    _567_t3 = 135;
    goto BB661;
BB661:
    _567_$retval = _567_t3;
    return _567_$retval;
}


int main(void) {
  printf("%ld",_567_main());
  return 0;
}
