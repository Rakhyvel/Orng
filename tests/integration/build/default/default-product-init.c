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
int64_t _445_main(void);

/* Function definitions */
int64_t _445_main(void) {
    int64_t _445_t1;
    double _445_t2;
    struct0 _446_x;
    int64_t _445_$retval;
    _445_t1 = 137;
    _445_t2 = 0.0e+00;
    _446_x = (struct0) {_445_t1, _445_t2};
    _445_$retval = _446_x._0;
    return _445_$retval;
}

int main(void) {
  printf("%ld",_445_main());
  return 0;
}
