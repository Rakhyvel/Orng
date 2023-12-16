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
int64_t _970_main(void);

/* Function definitions */
int64_t _970_main(void){
    int64_t _970_t2;
    struct0 _971_x;
    int64_t _970_$retval;
    _970_t2 = 125;
    _971_x = (struct0) {.tag=1, ._1=_970_t2};
    _970_$retval = _971_x._1;
    return _970_$retval;
}

int main(void) {
  printf("%ld",_970_main());
  return 0;
}
