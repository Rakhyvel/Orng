/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
} struct0;

/* Function forward definitions */
int64_t _844_main(void);

/* Function definitions */
int64_t _844_main(void) {
    struct0 _845_x;
    uint8_t _844_t4;
    int64_t _844_t1;
    uint64_t _844_t5;
    uint64_t _844_t6;
    uint8_t _844_t7;
    int64_t _844_$retval;
    _845_x = (struct0) {.tag=1};
    _844_t4 = 0;
    if (_844_t4) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _844_t1 = 168;
    goto BB5;
BB6:
    _844_t5 = 1;
    _844_t6 = _845_x.tag;
    _844_t7 = _844_t6 == _844_t5;
    if (_844_t7) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _844_$retval = _844_t1;
    return _844_$retval;
BB8:
    _844_t1 = 171;
    goto BB5;
BB10:
    (void)_845_x;
    _844_t1 = 0;
    goto BB5;
}

int main(void) {
  printf("%ld",_844_main());
  return 0;
}
