/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _826_main(void);

/* Function definitions */
int64_t _826_main(void) {
    int64_t _826_t1;
    uint8_t _826_t3;
    int64_t _826_t0;
    int64_t _826_t6;
    uint8_t _826_t7;
    int64_t _826_$retval;
    int64_t _826_t4;
    uint8_t _826_t5;
    _826_t1 = 3;
    _826_t3 = 0;
    if (_826_t3) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _826_t0 = 1;
    goto BB5;
BB6:
    _826_t4 = 2;
    _826_t5 = _826_t1 == _826_t4;
    if (_826_t5) {
        goto BB8;
    } else {
        goto BB9;
    }
BB5:
    _826_$retval = _826_t0;
    return _826_$retval;
BB8:
    _826_t0 = 2;
    goto BB5;
BB9:
    _826_t6 = 3;
    _826_t7 = _826_t1 == _826_t6;
    if (_826_t7) {
        goto BB11;
    } else {
        goto BB13;
    }
BB11:
    _826_t0 = 230;
    goto BB5;
BB13:
    _826_t0 = 3;
    goto BB5;
}

int main(void) {
  printf("%ld",_826_main());
  return 0;
}
