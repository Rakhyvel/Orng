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
int64_t _1473_main(void);

/* Function definitions */
int64_t _1473_main(void) {
    uint32_t _1473_t1;
    int64_t _1473_t2;
    double _1473_t3;
    struct0 _1474_x;
    int64_t _1473_$retval;
    _1473_t1 = 960;
    _1473_t2 = 247;
    _1473_t3 = 3.14e+00;
    _1474_x = (struct0) {_1473_t1, _1473_t2, _1473_t3};
    _1473_$retval = _1474_x._1;
    return _1473_$retval;
}

int main(void) {
  printf("%ld",_1473_main());
  return 0;
}
