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
int64_t _673_main(void);

/* Function definitions */
int64_t _673_main(void) {
    uint8_t _673_t1;
    int64_t _673_t2;
    struct0 _673_t0;
    struct0 _674_x;
    int64_t _673_$retval;
    _673_t1 = 1;
    if (_673_t1) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _673_t2 = 125;
    _673_t0 = (struct0) {.tag=1, ._1=_673_t2};
    goto BB3;
BB5:
    _673_t0 = (struct0) {.tag=0};
    goto BB3;
BB3:
    _674_x = _673_t0;
    _673_$retval = _674_x._1;
    return _673_$retval;
}

int main(void) {
  printf("%ld",_673_main());
  return 0;
}
