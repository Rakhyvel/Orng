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
int64_t _1637_main(void);

/* Function definitions */
int64_t _1637_main(void){
    uint32_t _1637_t1;
    int64_t _1637_t2;
    double _1637_t3;
    struct0 _1638_x;
    int64_t _1637_$retval;
    _1637_t1 = 960;
    _1637_t2 = 247;
    _1637_t3 = 3.14e+00;
    _1638_x = (struct0) {_1637_t1, _1637_t2, _1637_t3};
    _1637_$retval = _1638_x._1;
    return _1637_$retval;
}

int main(void) {
  printf("%ld",_1637_main());
  return 0;
}
