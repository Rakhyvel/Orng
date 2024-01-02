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
int64_t _1511_main(void);

/* Function definitions */
int64_t _1511_main(void){
    uint32_t _1511_t1;
    int64_t _1511_t2;
    double _1511_t3;
    struct struct0 _1512_x;
    int64_t _1511_$retval;
    _1511_t1 = 960;
    _1511_t2 = 247;
    _1511_t3 = 3.14e+00;
    _1512_x = (struct struct0) {_1511_t1, _1511_t2, _1511_t3};
    _1511_$retval = _1512_x._1;
    return _1511_$retval;
}

int main(void) {
  printf("%ld",_1511_main());
  return 0;
}
