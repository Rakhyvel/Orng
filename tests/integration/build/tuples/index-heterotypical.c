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
int64_t _1544_main(void);

/* Function definitions */
int64_t _1544_main(void){
    uint32_t _1544_t1;
    int64_t _1544_t2;
    double _1544_t3;
    struct struct0 _1545_x;
    int64_t _1544_$retval;
    _1544_t1 = 960;
    _1544_t2 = 247;
    _1544_t3 = 3.14e+00;
    _1545_x = (struct struct0) {_1544_t1, _1544_t2, _1544_t3};
    _1544_$retval = _1545_x._1;
    return _1544_$retval;
}

int main(void) {
  printf("%ld",_1544_main());
  return 0;
}
