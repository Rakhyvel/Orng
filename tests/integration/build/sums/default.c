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

/* Function forward definitions */
int64_t _987_main(void);

/* Function definitions */
int64_t _987_main(void) {
    int64_t _987_t0;
    struct0 _988_x;
    int64_t _987_$retval;
    _987_t0 = 102;
    _988_x = (struct0) {.tag=0, ._0=_987_t0};
    _987_$retval = _988_x._0;
    return _987_$retval;
}

int main(void) {
  printf("%ld",_987_main());
  return 0;
}
