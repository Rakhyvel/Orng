/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    double _1;
};

/* Function forward definitions */
int64_t _532_main(void);

/* Function definitions */
int64_t _532_main(void){
    int64_t _532_t1;
    double _532_t2;
    struct struct0 _533_x;
    int64_t _532_$retval;
    _532_t1 = 137;
    _532_t2 = 0.0e+00;
    _533_x = (struct struct0) {_532_t1, _532_t2};
    _532_$retval = _533_x._0;
    return _532_$retval;
}

int main(void) {
  printf("%ld",_532_main());
  return 0;
}
