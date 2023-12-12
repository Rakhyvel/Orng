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
int64_t _767_main(void);

/* Function definitions */
int64_t _767_main(void) {
    int64_t _767_t2;
    struct0 _768_x;
    int64_t _767_$retval;
    _767_t2 = 125;
    _768_x = (struct0) {.tag=1, ._1=_767_t2};
    _767_$retval = _768_x._1;
    return _767_$retval;
}

int main(void) {
  printf("%ld",_767_main());
  return 0;
}
