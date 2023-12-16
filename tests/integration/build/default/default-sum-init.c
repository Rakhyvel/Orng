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
int64_t _548_main(void);

/* Function definitions */
int64_t _548_main(void){
    int64_t _548_t0;
    struct0 _549_x;
    int64_t _548_$retval;
    _548_t0 = 134;
    _549_x = (struct0) {.tag=0, ._0=_548_t0};
    _548_$retval = _549_x._0;
    return _548_$retval;
}

int main(void) {
  printf("%ld",_548_main());
  return 0;
}
