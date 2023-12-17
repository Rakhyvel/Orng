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
        int64_t _0;
    };
} struct0;

/* Function forward definitions */
int64_t _633_main(void);

/* Function definitions */
int64_t _633_main(void){
    int64_t _633_t0;
    struct0 _634_x;
    int64_t _633_$retval;
    _633_t0 = 134;
    _634_x = (struct0) {.tag=0, ._0=_633_t0};
    _633_$retval = _634_x._0;
    return _633_$retval;
}

int main(void) {
  printf("%ld",_633_main());
  return 0;
}
