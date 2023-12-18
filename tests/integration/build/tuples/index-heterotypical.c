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
int64_t _1736_main(void);

/* Function definitions */
int64_t _1736_main(void){
    uint32_t _1736_t1;
    int64_t _1736_t2;
    double _1736_t3;
    struct0 _1737_x;
    int64_t _1736_$retval;
    _1736_t1 = 960;
    _1736_t2 = 247;
    _1736_t3 = 3.14e+00;
    _1737_x = (struct0) {_1736_t1, _1736_t2, _1736_t3};
    _1736_$retval = _1737_x._1;
    return _1736_$retval;
}

int main(void) {
  printf("%ld",_1736_main());
  return 0;
}
