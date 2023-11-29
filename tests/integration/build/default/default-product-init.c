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
int64_t _416_main(void);

/* Function definitions */
int64_t _416_main(void) {
    int64_t _416_t1;
    double _416_t2;
    struct0 _417_x;
    int64_t _416_$retval;
    _416_t1 = 137;
    _416_t2 = 0;
    _417_x = (struct0) {_416_t1, _416_t2};
    _416_$retval = _417_x._0;
    return _416_$retval;
}

int main(void) {
  printf("%ld",_416_main());
  return 0;
}
