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
int64_t _586_main(void);


/* Function definitions */
int64_t _586_main(void){
    int64_t _586_t1;
    double _586_t2;
    struct struct0 _587_x;
    int64_t _586_t5;
    uint8_t _586_t7;
    int64_t _586_t4;
    double _586_t8;
    uint8_t _586_t10;
    int64_t _586_$retval;
    _586_t1 = 0;
    _586_t2 = 0e0;
    _587_x = (struct struct0) {_586_t1, _586_t2};
    _586_t5 = 0;
    _586_t7 = _587_x._0==_586_t5;
    if (_586_t7) {
        goto BB664;
    } else {
        goto BB671;
    }
BB664:
    _586_t8 = 0e0;
    _586_t10 = _587_x._1==_586_t8;
    if (_586_t10) {
        goto BB667;
    } else {
        goto BB671;
    }
BB671:
    _586_t4 = 0;
    goto BB670;
BB667:
    _586_t4 = 135;
    goto BB670;
BB670:
    _586_$retval = _586_t4;
    return _586_$retval;
}


int main(void) {
  printf("%ld",_586_main());
  return 0;
}
