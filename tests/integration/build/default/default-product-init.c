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
int64_t _395_main(void);

/* Function definitions */
int64_t _395_main(void) {
    int64_t _395_t1;
    double _395_t2;
    struct0 _396_x;
    int64_t _395_$retval;
    _395_t1 = 137;
    _395_t2 = 0;
    _396_x = (struct0) {_395_t1, _395_t2};
    _395_$retval = _396_x._0;
    return _395_$retval;
}

int main(void) {
  printf("%ld",_395_main());
  return 0;
}
