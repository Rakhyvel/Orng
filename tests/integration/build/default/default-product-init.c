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
int64_t _221_main(void);

/* Function definitions */
int64_t _221_main(void) {
    int64_t _221_t1;
    double _221_t2;
    struct0 _222_x;
    int64_t _221_$retval;
    _221_t1 = 137;
    _221_t2 = 0;
    _222_x = (struct0) {_221_t1, _221_t2};
    _221_$retval = _222_x._0;
    return _221_$retval;
}

int main(void) {
  printf("%ld",_221_main());
  return 0;
}
