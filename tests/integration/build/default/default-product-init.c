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
int64_t _453_main(void);

/* Function definitions */
int64_t _453_main(void){
    int64_t _453_t1;
    double _453_t2;
    struct0 _454_x;
    int64_t _453_$retval;
    _453_t1 = 137;
    _453_t2 = 0.0e+00;
    _454_x = (struct0) {_453_t1, _453_t2};
    _453_$retval = _454_x._0;
    return _453_$retval;
}

int main(void) {
  printf("%ld",_453_main());
  return 0;
}
