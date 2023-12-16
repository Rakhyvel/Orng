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
int64_t _981_main(void);

/* Function definitions */
int64_t _981_main(void){
    int64_t _981_t2;
    struct0 _982_x;
    int64_t _981_$retval;
    _981_t2 = 125;
    _982_x = (struct0) {.tag=1, ._1=_981_t2};
    _981_$retval = _982_x._1;
    return _981_$retval;
}

int main(void) {
  printf("%ld",_981_main());
  return 0;
}
