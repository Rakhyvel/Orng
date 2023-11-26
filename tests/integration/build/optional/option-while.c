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
int64_t _35_main(void);

/* Function definitions */
int64_t _35_main(void) {
    int64_t _35_$retval;
    uint8_t _35_t1;
    struct0 _36_y;
    uint64_t _35_t4;
    int64_t _35_t3;
BB1:
    _35_t1 = 0;
    if (_35_t1) {
        goto BB1;
    } else {
        goto BB5;
    }
BB5:
    _36_y = (struct0) {.tag=0};
    _35_t4 = 0;
    if (_35_t4) {
        goto BB7;
    } else {
        goto BB10;
    }
BB7:
    _35_t3 = _36_y._1;
    goto BB9;
BB10:
    _35_t3 = 123;
    goto BB9;
BB9:
    _35_$retval = _35_t3;
    return _35_$retval;
}

int main(void) {
  printf("%ld",_35_main());
  return 0;
}
