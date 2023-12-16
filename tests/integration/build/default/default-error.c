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
        int64_t _0;
        double _1;
    };
} struct0;

/* Function forward definitions */
int64_t _419_main(void);

/* Function definitions */
int64_t _419_main(void){
    int64_t _419_t0;
    struct0 _420_x;
    int64_t _419_$retval;
    _419_t0 = 139;
    _420_x = (struct0) {.tag=0, ._0=_419_t0};
    _419_$retval = _420_x._0;
    return _419_$retval;
}

int main(void) {
  printf("%ld",_419_main());
  return 0;
}
