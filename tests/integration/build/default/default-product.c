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
int64_t _574_main(void);


/* Function definitions */
int64_t _574_main(void){
    int64_t _574_t1;
    double _574_t2;
    struct struct0 _575_x;
    int64_t _574_t5;
    uint8_t _574_t7;
    int64_t _574_t4;
    double _574_t8;
    uint8_t _574_t10;
    int64_t _574_$retval;
    _574_t1 = 0;
    _574_t2 = 0e0;
    _575_x = (struct struct0) {_574_t1, _574_t2};
    _574_t5 = 0;
    _574_t7 = _575_x._0==_574_t5;
    if (_574_t7) {
        goto BB651;
    } else {
        goto BB658;
    }
BB651:
    _574_t8 = 0e0;
    _574_t10 = _575_x._1==_574_t8;
    if (_574_t10) {
        goto BB654;
    } else {
        goto BB658;
    }
BB658:
    _574_t4 = 0;
    goto BB657;
BB654:
    _574_t4 = 135;
    goto BB657;
BB657:
    _574_$retval = _574_t4;
    return _574_$retval;
}


int main(void) {
  printf("%ld",_574_main());
  return 0;
}
