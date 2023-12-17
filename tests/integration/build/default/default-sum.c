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
int64_t _640_main(void);

/* Function definitions */
int64_t _640_main(void){
    int64_t _640_t0;
    struct0 _641_x;
    int64_t _640_t3;
    uint8_t _640_t5;
    int64_t _640_t2;
    int64_t _640_$retval;
    _640_t0 = 0;
    _641_x = (struct0) {.tag=0, ._0=_640_t0};
    _640_t3 = 0;
    _640_t5 = _641_x._0 == _640_t3;
    if (_640_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _640_t2 = 133;
    goto BB6;
BB7:
    _640_t2 = 0;
    goto BB6;
BB6:
    _640_$retval = _640_t2;
    return _640_$retval;
}

int main(void) {
  printf("%ld",_640_main());
  return 0;
}
