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
int64_t _1441_main(void);

/* Function definitions */
int64_t _1441_main(void){
    int64_t _1441_t0;
    struct0 _1442_x;
    int64_t _1441_$retval;
    _1441_t0 = 211;
    _1442_x = (struct0) {.tag=1, ._1=_1441_t0};
    _1441_$retval = _1442_x._1;
    return _1441_$retval;
}

int main(void) {
  printf("%ld",_1441_main());
  return 0;
}
