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
int64_t _464_main(void);

/* Function definitions */
int64_t _464_main(void){
    int64_t _464_t1;
    double _464_t2;
    struct0 _465_x;
    int64_t _464_$retval;
    _464_t1 = 137;
    _464_t2 = 0.0e+00;
    _465_x = (struct0) {_464_t1, _464_t2};
    _464_$retval = _465_x._0;
    return _464_$retval;
}

int main(void) {
  printf("%ld",_464_main());
  return 0;
}
