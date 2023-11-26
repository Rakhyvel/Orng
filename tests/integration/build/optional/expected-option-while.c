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
int64_t _25_main(void);

/* Function definitions */
int64_t _25_main(void) {
    int64_t _25_$retval;
    uint8_t _25_t1;
    struct0 _26_y;
    uint64_t _25_t4;
    int64_t _25_t3;
BB1:
    _25_t1 = 0;
    if (_25_t1) {
        goto BB1;
    } else {
        goto BB5;
    }
BB5:
    _26_y = (struct0) {.tag=0};
    _25_t4 = 0;
    if (_25_t4) {
        goto BB7;
    } else {
        goto BB10;
    }
BB7:
    _25_t3 = _26_y._1;
    goto BB9;
BB10:
    _25_t3 = 116;
    goto BB9;
BB9:
    _25_$retval = _25_t3;
    return _25_$retval;
}

int main(void) {
  printf("%ld",_25_main());
  return 0;
}
