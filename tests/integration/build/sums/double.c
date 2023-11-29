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
    };
} struct0;

typedef struct {
    uint64_t tag;
    union {
        struct0 _0;
    };
} struct1;

/* Function forward definitions */
int64_t _16_main(void);

/* Function definitions */
int64_t _16_main(void) {
    int64_t _16_t0;
    struct0 _16_t1;
    struct1 _17_x;
    int64_t _16_$retval;
    _16_t0 = 4;
    _16_t1 = (struct0) {.tag=0, ._0=_16_t0};
    _17_x = (struct1) {.tag=0, ._0=_16_t1};
    _17_x._0._0 = 104;
    _16_$retval = _17_x._0._0;
    return _16_$retval;
}

int main(void) {
  printf("%ld",_16_main());
  return 0;
}
