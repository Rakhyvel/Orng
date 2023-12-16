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
        uint32_t _2;
    };
} struct0;

/* Function forward definitions */
int64_t _1146_main(void);

/* Function definitions */
int64_t _1146_main(void){
    int64_t _1146_t1;
    struct0 _1147_x;
    int64_t _1146_$retval;
    _1146_t1 = 172;
    _1147_x = (struct0) {.tag=0, ._0=_1146_t1};
    _1146_$retval = _1147_x._0;
    return _1146_$retval;
}

int main(void) {
  printf("%ld",_1146_main());
  return 0;
}
