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
int64_t _801_main(void);

/* Function definitions */
int64_t _801_main(void) {
    int64_t _801_t0;
    struct0 _802_x;
    int64_t _801_t4;
    int64_t _801_$retval;
    _801_t0 = 4;
    _802_x = (struct0) {.tag=1, ._1=_801_t0};
    _802_x = (struct0) {.tag=0};
    _801_t4 = 113;
    _802_x = (struct0) {.tag=1, ._1=_801_t4};
    _801_$retval = _802_x._1;
    return _801_$retval;
}

int main(void) {
  printf("%ld",_801_main());
  return 0;
}
