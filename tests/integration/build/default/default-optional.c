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
int64_t _218_main(void);

/* Function definitions */
int64_t _218_main(void) {
    struct0 _219_x;
    uint64_t _218_t2;
    int64_t _218_t1;
    int64_t _218_$retval;
    _219_x = (struct0) {.tag=0};
    _218_t2 = 0;
    if (_218_t2) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _218_t1 = _219_x._1;
    goto BB3;
BB4:
    _218_t1 = 138;
    goto BB3;
BB3:
    _218_$retval = _218_t1;
    return _218_$retval;
}

int main(void) {
  printf("%ld",_218_main());
  return 0;
}
