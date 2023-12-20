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
int64_t _1188_main(void);

/* Function definitions */
int64_t _1188_main(void){
    int64_t _1188_t1;
    struct0 _1189_x;
    int64_t _1188_$retval;
    _1188_t1 = 171;
    _1189_x = (struct0) {.tag=0, ._0=_1188_t1};
    _1188_$retval = _1189_x._0;
    return _1188_$retval;
}

int main(void) {
  printf("%ld",_1188_main());
  return 0;
}
