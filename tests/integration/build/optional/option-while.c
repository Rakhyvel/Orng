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
int64_t _706_main(void);

/* Function definitions */
int64_t _706_main(void) {
    int64_t _706_$retval;
    uint8_t _706_t1;
    struct0 _707_y;
    uint64_t _706_t4;
    int64_t _706_t3;
BB1:
    _706_t1 = 0;
    if (_706_t1) {
        goto BB1;
    } else {
        goto BB5;
    }
BB5:
    _707_y = (struct0) {.tag=0};
    _706_t4 = 0;
    if (_706_t4) {
        goto BB7;
    } else {
        goto BB10;
    }
BB7:
    _706_t3 = _707_y._1;
    goto BB9;
BB10:
    _706_t3 = 123;
    goto BB9;
BB9:
    _706_$retval = _706_t3;
    return _706_$retval;
}

int main(void) {
  printf("%ld",_706_main());
  return 0;
}
