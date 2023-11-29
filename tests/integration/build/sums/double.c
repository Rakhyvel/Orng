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
int64_t _1127_main(void);

/* Function definitions */
int64_t _1127_main(void) {
    int64_t _1127_t0;
    struct0 _1127_t1;
    struct1 _1128_x;
    int64_t _1127_$retval;
    _1127_t0 = 4;
    _1127_t1 = (struct0) {.tag=0, ._0=_1127_t0};
    _1128_x = (struct1) {.tag=0, ._0=_1127_t1};
    _1128_x._0._0 = 104;
    _1127_$retval = _1128_x._0._0;
    return _1127_$retval;
}

int main(void) {
  printf("%ld",_1127_main());
  return 0;
}
