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
int64_t _588_main(void);


/* Function definitions */
int64_t _588_main(void){
    int64_t _588_t1;
    double _588_t2;
    struct struct0 _589_x;
    int64_t _588_t5;
    uint8_t _588_t7;
    int64_t _588_t4;
    double _588_t8;
    uint8_t _588_t10;
    int64_t _588_$retval;
    _588_t1 = 0;
    _588_t2 = 0e0;
    _589_x = (struct struct0) {_588_t1, _588_t2};
    _588_t5 = 0;
    _588_t7 = _589_x._0==_588_t5;
    if (_588_t7) {
        goto BB666;
    } else {
        goto BB673;
    }
BB666:
    _588_t8 = 0e0;
    _588_t10 = _589_x._1==_588_t8;
    if (_588_t10) {
        goto BB669;
    } else {
        goto BB673;
    }
BB673:
    _588_t4 = 0;
    goto BB672;
BB669:
    _588_t4 = 135;
    goto BB672;
BB672:
    _588_$retval = _588_t4;
    return _588_$retval;
}


int main(void) {
  printf("%ld",_588_main());
  return 0;
}
