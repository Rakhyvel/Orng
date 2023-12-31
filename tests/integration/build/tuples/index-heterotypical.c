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
int64_t _1508_main(void);

/* Function definitions */
int64_t _1508_main(void){
    uint32_t _1508_t1;
    int64_t _1508_t2;
    double _1508_t3;
    struct struct0 _1509_x;
    int64_t _1508_$retval;
    _1508_t1 = 960;
    _1508_t2 = 247;
    _1508_t3 = 3.14e+00;
    _1509_x = (struct struct0) {_1508_t1, _1508_t2, _1508_t3};
    _1508_$retval = _1509_x._1;
    return _1508_$retval;
}

int main(void) {
  printf("%ld",_1508_main());
  return 0;
}
