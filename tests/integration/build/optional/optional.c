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
int64_t _816_main(void);

/* Function definitions */
int64_t _816_main(void) {
    int64_t _816_t0;
    struct0 _817_x;
    int64_t _816_t3;
    int64_t _816_$retval;
    _816_t0 = 4;
    _817_x = (struct0) {.tag=1, ._1=_816_t0};
    _817_x = (struct0) {.tag=0};
    _816_t3 = 113;
    _817_x = (struct0) {.tag=1, ._1=_816_t3};
    _816_$retval = _817_x._1;
    return _816_$retval;
}

int main(void) {
  printf("%ld",_816_main());
  return 0;
}
