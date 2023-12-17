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
        uint8_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _1543_main(void);

/* Function definitions */
int64_t _1543_main(void){
    int64_t _1543_t0;
    struct0 _1544_x;
    int64_t _1543_$retval;
    _1543_t0 = 102;
    _1544_x = (struct0) {.tag=0, ._0=_1543_t0};
    _1543_$retval = _1544_x._0;
    return _1543_$retval;
}

int main(void) {
  printf("%ld",_1543_main());
  return 0;
}
