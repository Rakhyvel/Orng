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
int64_t _23_main(void);

/* Function definitions */
int64_t _23_main(void) {
    struct0 _24_x;
    uint64_t _23_t2;
    int64_t _23_t1;
    int64_t _23_$retval;
    _24_x = (struct0) {.tag=0};
    _23_t2 = 0;
    if (_23_t2) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _23_t1 = _24_x._1;
    goto BB3;
BB4:
    _23_t1 = 138;
    goto BB3;
BB3:
    _23_$retval = _23_t1;
    return _23_$retval;
}

int main(void) {
  printf("%ld",_23_main());
  return 0;
}
