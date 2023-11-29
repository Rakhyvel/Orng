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
int64_t _1158_main(void);

/* Function definitions */
int64_t _1158_main(void) {
    int64_t _1158_t0;
    struct0 _1159_x;
    int64_t _1158_$retval;
    _1158_t0 = 210;
    _1159_x = (struct0) {.tag=1, ._1=_1158_t0};
    _1158_$retval = _1159_x._1;
    return _1158_$retval;
}

int main(void) {
  printf("%ld",_1158_main());
  return 0;
}
