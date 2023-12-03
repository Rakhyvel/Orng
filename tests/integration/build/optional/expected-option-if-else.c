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
int64_t _735_main(void);

/* Function definitions */
int64_t _735_main(void) {
    int64_t _735_t2;
    struct0 _736_x;
    int64_t _735_$retval;
    _735_t2 = 125;
    _736_x = (struct0) {.tag=1, ._1=_735_t2};
    _735_$retval = _736_x._1;
    return _735_$retval;
}

int main(void) {
  printf("%ld",_735_main());
  return 0;
}
