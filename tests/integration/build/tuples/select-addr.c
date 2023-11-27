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
int64_t _1101_main(void);

/* Function definitions */
int64_t _1101_main(void) {
    int64_t _1101_t1;
    int64_t _1101_t2;
    struct0 _1102_x;
    struct0* _1101_t4;
    struct0* _1101_t5;
    int64_t _1101_$retval;
    _1101_t1 = 1;
    _1101_t2 = 2;
    _1102_x = (struct0) {_1101_t1, _1101_t2};
    _1101_t4 = &_1102_x;
    (*_1101_t4)._0 = 76;
    _1101_t5 = &_1102_x;
    _1101_$retval = (*_1101_t5)._0;
    return _1101_$retval;
}

int main(void) {
  printf("%ld",_1101_main());
  return 0;
}
