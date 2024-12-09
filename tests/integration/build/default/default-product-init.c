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
int64_t _563_main(void);


/* Function definitions */
int64_t _563_main(void){
    int64_t _563_t1;
    double _563_t2;
    struct struct0 _564_x;
    int64_t _563_$retval;
    _563_t1 = 137;
    _563_t2 = 0e0;
    _564_x = (struct struct0) {_563_t1, _563_t2};
    _563_$retval = _564_x._0;
    return _563_$retval;
}


int main(void) {
  printf("%ld",_563_main());
  return 0;
}
