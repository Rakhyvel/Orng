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
int64_t _1088_main(void);

/* Function definitions */
int64_t _1088_main(void){
    int64_t _1088_t0;
    struct0 _1089_x;
    int64_t _1088_t4;
    int64_t _1088_$retval;
    _1088_t0 = 4;
    _1089_x = (struct0) {.tag=1, ._1=_1088_t0};
    _1089_x = (struct0) {.tag=0};
    _1088_t4 = 113;
    _1089_x = (struct0) {.tag=1, ._1=_1088_t4};
    _1088_$retval = _1089_x._1;
    return _1088_$retval;
}

int main(void) {
  printf("%ld",_1088_main());
  return 0;
}
