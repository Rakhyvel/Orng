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
int64_t _1041_main(void);

/* Function definitions */
int64_t _1041_main(void){
    int64_t _1041_t2;
    struct0 _1042_x;
    int64_t _1041_$retval;
    _1041_t2 = 125;
    _1042_x = (struct0) {.tag=1, ._1=_1041_t2};
    _1041_$retval = _1042_x._1;
    return _1041_$retval;
}

int main(void) {
  printf("%ld",_1041_main());
  return 0;
}
