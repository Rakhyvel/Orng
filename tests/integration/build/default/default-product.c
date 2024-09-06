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
int64_t _566_main(void);


/* Function definitions */
int64_t _566_main(void){
    int64_t _566_t1;
    double _566_t2;
    struct struct0 _567_x;
    int64_t _566_t5;
    uint8_t _566_t7;
    int64_t _566_t4;
    double _566_t8;
    uint8_t _566_t10;
    int64_t _566_$retval;
    _566_t1 = 0;
    _566_t2 = 0e0;
    _567_x = (struct struct0) {_566_t1, _566_t2};
    _566_t5 = 0;
    _566_t7 = _567_x._0==_566_t5;
    if (_566_t7) {
        goto BB645;
    } else {
        goto BB652;
    }
BB645:
    _566_t8 = 0e0;
    _566_t10 = _567_x._1==_566_t8;
    if (_566_t10) {
        goto BB648;
    } else {
        goto BB652;
    }
BB652:
    _566_t4 = 0;
    goto BB651;
BB648:
    _566_t4 = 135;
    goto BB651;
BB651:
    _566_$retval = _566_t4;
    return _566_$retval;
}


int main(void) {
  printf("%ld",_566_main());
  return 0;
}
