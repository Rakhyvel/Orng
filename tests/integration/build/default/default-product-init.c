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
int64_t _312_main(void);

/* Function definitions */
int64_t _312_main(void) {
    int64_t _312_t1;
    double _312_t2;
    struct0 _313_x;
    int64_t _312_$retval;
    _312_t1 = 137;
    _312_t2 = 0.0e+00;
    _313_x = (struct0) {_312_t1, _312_t2};
    _312_$retval = _313_x._0;
    return _312_$retval;
}

int main(void) {
  printf("%ld",_312_main());
  return 0;
}
