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
int64_t _1028_main(void);

/* Function definitions */
int64_t _1028_main(void){
    int64_t _1028_t0;
    struct0 _1029_x;
    int64_t _1028_t4;
    int64_t _1028_$retval;
    _1028_t0 = 4;
    _1029_x = (struct0) {.tag=1, ._1=_1028_t0};
    _1029_x = (struct0) {.tag=0};
    _1028_t4 = 113;
    _1029_x = (struct0) {.tag=1, ._1=_1028_t4};
    _1028_$retval = _1029_x._1;
    return _1028_$retval;
}

int main(void) {
  printf("%ld",_1028_main());
  return 0;
}
