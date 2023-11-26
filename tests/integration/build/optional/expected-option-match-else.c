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
int64_t _13_main(void);

/* Function definitions */
int64_t _13_main(void) {
    uint8_t _13_t1;
    uint8_t _13_t3;
    int64_t _13_t10;
    struct0 _13_t0;
    int64_t _13_t8;
    int64_t _13_t6;
    struct0 _14_x;
    int64_t _13_$retval;
    uint8_t _13_t4;
    uint8_t _13_t5;
    _13_t1 = 1;
    _13_t3 = 0;
    if (_13_t3) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _13_t6 = 15;
    _13_t0 = (struct0) {.tag=1, ._1=_13_t6};
    goto BB4;
BB6:
    _13_t4 = 0;
    _13_t5 = _13_t1 == _13_t4;
    if (_13_t5) {
        goto BB8;
    } else {
        goto BB10;
    }
BB4:
    _14_x = _13_t0;
    _13_$retval = _14_x._1;
    return _13_$retval;
BB8:
    _13_t8 = 15;
    _13_t0 = (struct0) {.tag=1, ._1=_13_t8};
    goto BB4;
BB10:
    _13_t10 = 128;
    _13_t0 = (struct0) {.tag=1, ._1=_13_t10};
    goto BB4;
}

int main(void) {
  printf("%ld",_13_main());
  return 0;
}
