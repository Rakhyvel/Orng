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
int64_t _1173_main(void);

/* Function definitions */
int64_t _1173_main(void){
    int64_t _1173_t0;
    struct0 _1174_x;
    int64_t _1173_t4;
    int64_t _1173_$retval;
    _1173_t0 = 4;
    _1174_x = (struct0) {.tag=1, ._1=_1173_t0};
    _1174_x = (struct0) {.tag=0};
    _1173_t4 = 113;
    _1174_x = (struct0) {.tag=1, ._1=_1173_t4};
    _1173_$retval = _1174_x._1;
    return _1173_$retval;
}

int main(void) {
  printf("%ld",_1173_main());
  return 0;
}
