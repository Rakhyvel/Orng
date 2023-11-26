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
int64_t _696_main(void);

/* Function definitions */
int64_t _696_main(void) {
    int64_t _696_$retval;
    uint8_t _696_t1;
    struct0 _697_y;
    uint64_t _696_t4;
    int64_t _696_t3;
BB1:
    _696_t1 = 0;
    if (_696_t1) {
        goto BB1;
    } else {
        goto BB5;
    }
BB5:
    _697_y = (struct0) {.tag=0};
    _696_t4 = 0;
    if (_696_t4) {
        goto BB7;
    } else {
        goto BB10;
    }
BB7:
    _696_t3 = _697_y._1;
    goto BB9;
BB10:
    _696_t3 = 116;
    goto BB9;
BB9:
    _696_$retval = _696_t3;
    return _696_$retval;
}

int main(void) {
  printf("%ld",_696_main());
  return 0;
}
