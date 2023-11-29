/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _1559_main(void);

/* Function definitions */
int64_t _1559_main(void) {
    int64_t _1559_t1;
    int64_t _1559_t2;
    struct0 _1560_x;
    struct0* _1559_t4;
    struct0* _1559_t5;
    int64_t _1559_$retval;
    _1559_t1 = 1;
    _1559_t2 = 2;
    _1560_x = (struct0) {_1559_t1, _1559_t2};
    _1559_t4 = &_1560_x;
    (*_1559_t4)._0 = 76;
    _1559_t5 = &_1560_x;
    _1559_$retval = (*_1559_t5)._0;
    return _1559_$retval;
}

int main(void) {
  printf("%ld",_1559_main());
  return 0;
}
