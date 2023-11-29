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
int64_t _789_main(void);

/* Function definitions */
int64_t _789_main(void) {
    int64_t _789_t10;
    struct0 _790_x;
    int64_t _789_$retval;
    _789_t10 = 128;
    _790_x = (struct0) {.tag=1, ._1=_789_t10};
    _789_$retval = _790_x._1;
    return _789_$retval;
}

int main(void) {
  printf("%ld",_789_main());
  return 0;
}
