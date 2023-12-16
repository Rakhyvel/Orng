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
int64_t _484_main(void);

/* Function definitions */
int64_t _484_main(void){
    int64_t _484_t0;
    struct0 _485_x;
    int64_t _484_t3;
    uint8_t _484_t5;
    int64_t _484_t2;
    int64_t _484_$retval;
    _484_t0 = 0;
    _485_x = (struct0) {.tag=0, ._0=_484_t0};
    _484_t3 = 0;
    _484_t5 = _485_x._0 == _484_t3;
    if (_484_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _484_t2 = 133;
    goto BB6;
BB7:
    _484_t2 = 0;
    goto BB6;
BB6:
    _484_$retval = _484_t2;
    return _484_$retval;
}

int main(void) {
  printf("%ld",_484_main());
  return 0;
}
