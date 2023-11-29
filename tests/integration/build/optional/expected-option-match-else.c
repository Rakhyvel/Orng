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
    int64_t _13_t10;
    struct0 _14_x;
    int64_t _13_$retval;
    _13_t10 = 128;
    _14_x = (struct0) {.tag=1, ._1=_13_t10};
    _13_$retval = _14_x._1;
    return _13_$retval;
}

int main(void) {
  printf("%ld",_13_main());
  return 0;
}
