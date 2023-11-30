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
int64_t _941_main(void);

/* Function definitions */
int64_t _941_main(void) {
    int64_t _941_t10;
    struct0 _942_x;
    int64_t _941_$retval;
    _941_t10 = 128;
    _942_x = (struct0) {.tag=1, ._1=_941_t10};
    _941_$retval = _942_x._1;
    return _941_$retval;
}

int main(void) {
  printf("%ld",_941_main());
  return 0;
}
