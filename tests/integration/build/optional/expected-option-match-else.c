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
int64_t _983_main(void);

/* Function definitions */
int64_t _983_main(void){
    int64_t _983_t10;
    struct0 _984_x;
    int64_t _983_$retval;
    _983_t10 = 128;
    _984_x = (struct0) {.tag=1, ._1=_983_t10};
    _983_$retval = _984_x._1;
    return _983_$retval;
}

int main(void) {
  printf("%ld",_983_main());
  return 0;
}
