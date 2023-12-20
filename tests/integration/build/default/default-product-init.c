/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    double _1;
} struct0;

/* Function forward definitions */
int64_t _523_main(void);

/* Function definitions */
int64_t _523_main(void){
    int64_t _523_t1;
    double _523_t2;
    struct0 _524_x;
    int64_t _523_$retval;
    _523_t1 = 137;
    _523_t2 = 0.0e+00;
    _524_x = (struct0) {_523_t1, _523_t2};
    _523_$retval = _524_x._0;
    return _523_$retval;
}

int main(void) {
  printf("%ld",_523_main());
  return 0;
}
