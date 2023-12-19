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
int64_t _1743_main(void);

/* Function definitions */
int64_t _1743_main(void){
    uint32_t _1743_t1;
    int64_t _1743_t2;
    double _1743_t3;
    struct0 _1744_x;
    int64_t _1743_$retval;
    _1743_t1 = 960;
    _1743_t2 = 247;
    _1743_t3 = 3.14e+00;
    _1744_x = (struct0) {_1743_t1, _1743_t2, _1743_t3};
    _1743_$retval = _1744_x._1;
    return _1743_$retval;
}

int main(void) {
  printf("%ld",_1743_main());
  return 0;
}
