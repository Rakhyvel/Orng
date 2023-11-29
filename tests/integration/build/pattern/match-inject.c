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
int64_t _921_main(void);

/* Function definitions */
int64_t _921_main(void) {
    int64_t _921_t1;
    struct0 _922_x;
    int64_t _921_$retval;
    _921_t1 = 171;
    _922_x = (struct0) {.tag=0, ._0=_921_t1};
    _921_$retval = _922_x._0;
    return _921_$retval;
}

int main(void) {
  printf("%ld",_921_main());
  return 0;
}
