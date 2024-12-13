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
int64_t _580_main(void);


/* Function definitions */
int64_t _580_main(void){
    int64_t _580_t1;
    double _580_t2;
    struct struct0 _581_x;
    int64_t _580_$retval;
    _580_t1 = 137;
    _580_t2 = 0e0;
    _581_x = (struct struct0) {_580_t1, _580_t2};
    _580_$retval = _581_x._0;
    return _580_$retval;
}


int main(void) {
  printf("%ld",_580_main());
  return 0;
}
