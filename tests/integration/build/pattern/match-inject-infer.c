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
        uint8_t _1;
        uint32_t _2;
    };
} struct0;

/* Function forward definitions */
int64_t _881_main(void);

/* Function definitions */
int64_t _881_main(void) {
    int64_t _881_t1;
    struct0 _882_x;
    int64_t _881_$retval;
    _881_t1 = 172;
    _882_x = (struct0) {.tag=0, ._0=_881_t1};
    _881_$retval = _882_x._0;
    return _881_$retval;
}

int main(void) {
  printf("%ld",_881_main());
  return 0;
}
