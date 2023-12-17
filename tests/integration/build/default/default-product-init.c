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
int64_t _609_main(void);

/* Function definitions */
int64_t _609_main(void){
    int64_t _609_t1;
    double _609_t2;
    struct0 _610_x;
    int64_t _609_$retval;
    _609_t1 = 137;
    _609_t2 = 0.0e+00;
    _610_x = (struct0) {_609_t1, _609_t2};
    _609_$retval = _610_x._0;
    return _609_$retval;
}

int main(void) {
  printf("%ld",_609_main());
  return 0;
}
