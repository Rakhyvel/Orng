/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    double _1;
} struct0;

/* Function forward definitions */
int64_t _524_main(void);

/* Function definitions */
int64_t _524_main(void){
    int64_t _524_t1;
    double _524_t2;
    struct0 _525_x;
    int64_t _524_$retval;
    _524_t1 = 137;
    _524_t2 = 0.0e+00;
    _525_x = (struct0) {_524_t1, _524_t2};
    _524_$retval = _525_x._0;
    return _524_$retval;
}

int main(void) {
  printf("%ld",_524_main());
  return 0;
}
