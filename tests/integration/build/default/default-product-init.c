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
int64_t _558_main(void);


/* Function definitions */
int64_t _558_main(void){
    int64_t _558_t1;
    double _558_t2;
    struct struct0 _559_x;
    int64_t _558_$retval;
    _558_t1 = 137;
    _558_t2 = 0e0;
    _559_x = (struct struct0) {_558_t1, _558_t2};
    _558_$retval = _559_x._0;
    return _558_$retval;
}


int main(void) {
  printf("%ld",_558_main());
  return 0;
}
