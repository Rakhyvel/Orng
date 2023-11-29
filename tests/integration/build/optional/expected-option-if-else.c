/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _949_main(void);

/* Function definitions */
int64_t _949_main(void) {
    int64_t _949_t2;
    struct0 _950_x;
    int64_t _949_$retval;
    _949_t2 = 125;
    _950_x = (struct0) {.tag=1, ._1=_949_t2};
    _949_$retval = _950_x._1;
    return _949_$retval;
}

int main(void) {
  printf("%ld",_949_main());
  return 0;
}
