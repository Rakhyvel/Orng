/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint32_t _0;
    int64_t _1;
    double _2;
} struct0;

/* Function forward definitions */
int64_t _37_main(void);

/* Function definitions */
int64_t _37_main(void) {
    uint32_t _37_t1;
    int64_t _37_t2;
    double _37_t3;
    struct0 _38_x;
    int64_t _37_$retval;
    _37_t1 = 960;
    _37_t2 = 247;
    _37_t3 = 3.14e+00;
    _38_x = (struct0) {_37_t1, _37_t2, _37_t3};
    _37_$retval = _38_x._1;
    return _37_$retval;
}

int main(void) {
  printf("%ld",_37_main());
  return 0;
}
