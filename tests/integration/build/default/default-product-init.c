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
int64_t _252_main(void);

/* Function definitions */
int64_t _252_main(void) {
    int64_t _252_t1;
    double _252_t2;
    struct0 _253_x;
    int64_t _252_$retval;
    _252_t1 = 137;
    _252_t2 = 0;
    _253_x = (struct0) {_252_t1, _252_t2};
    _252_$retval = _253_x._0;
    return _252_$retval;
}

int main(void) {
  printf("%ld",_252_main());
  return 0;
}
