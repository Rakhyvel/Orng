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
int64_t _293_main(void);

/* Function definitions */
int64_t _293_main(void) {
    int64_t _293_t1;
    double _293_t2;
    struct0 _294_x;
    int64_t _293_$retval;
    _293_t1 = 137;
    _293_t2 = 0.0e+00;
    _294_x = (struct0) {_293_t1, _293_t2};
    _293_$retval = _294_x._0;
    return _293_$retval;
}

int main(void) {
  printf("%ld",_293_main());
  return 0;
}
