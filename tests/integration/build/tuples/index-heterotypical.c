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
int64_t _1726_main(void);

/* Function definitions */
int64_t _1726_main(void){
    uint32_t _1726_t1;
    int64_t _1726_t2;
    double _1726_t3;
    struct0 _1727_x;
    int64_t _1726_$retval;
    _1726_t1 = 960;
    _1726_t2 = 247;
    _1726_t3 = 3.14e+00;
    _1727_x = (struct0) {_1726_t1, _1726_t2, _1726_t3};
    _1726_$retval = _1727_x._1;
    return _1726_$retval;
}

int main(void) {
  printf("%ld",_1726_main());
  return 0;
}
