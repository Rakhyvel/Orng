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
int64_t _129_main(void);

/* Function definitions */
int64_t _129_main(void) {
    struct0 _130_x;
    uint8_t _129_t4;
    int64_t _129_t1;
    uint64_t _129_t5;
    uint64_t _129_t6;
    uint8_t _129_t7;
    int64_t _129_$retval;
    _130_x = (struct0) {.tag=1};
    _129_t4 = 0;
    if (_129_t4) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _129_t1 = 168;
    goto BB5;
BB6:
    _129_t5 = 1;
    _129_t6 = _130_x.tag;
    _129_t7 = _129_t6 == _129_t5;
    if (_129_t7) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _129_$retval = _129_t1;
    return _129_$retval;
BB8:
    _129_t1 = 171;
    goto BB5;
BB10:
    (void)_130_x;
    _129_t1 = 0;
    goto BB5;
}

int main(void) {
  printf("%ld",_129_main());
  return 0;
}
