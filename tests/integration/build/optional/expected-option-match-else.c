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
int64_t _1054_main(void);

/* Function definitions */
int64_t _1054_main(void){
    int64_t _1054_t10;
    struct0 _1055_x;
    int64_t _1054_$retval;
    _1054_t10 = 128;
    _1055_x = (struct0) {.tag=1, ._1=_1054_t10};
    _1054_$retval = _1055_x._1;
    return _1054_$retval;
}

int main(void) {
  printf("%ld",_1054_main());
  return 0;
}
