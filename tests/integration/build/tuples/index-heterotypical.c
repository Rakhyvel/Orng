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
    uint32_t _0;
    int64_t _1;
    double _2;
};

/* Function forward definitions */
int64_t _1516_main(void);

/* Function definitions */
int64_t _1516_main(void){
    uint32_t _1516_t1;
    int64_t _1516_t2;
    double _1516_t3;
    struct struct0 _1517_x;
    int64_t _1516_$retval;
    _1516_t1 = 960;
    _1516_t2 = 247;
    _1516_t3 = 3.14e+00;
    _1517_x = (struct struct0) {_1516_t1, _1516_t2, _1516_t3};
    _1516_$retval = _1517_x._1;
    return _1516_$retval;
}

int main(void) {
  printf("%ld",_1516_main());
  return 0;
}
