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
int64_t _822_main(void);

/* Function definitions */
int64_t _822_main(void) {
    int64_t _822_t0;
    struct0 _823_x;
    int64_t _822_$retval;
    _822_t0 = 172;
    _823_x = (struct0) {.tag=0, ._0=_822_t0};
    _822_$retval = _823_x._0;
    return _822_$retval;
}

int main(void) {
  printf("%ld",_822_main());
  return 0;
}
