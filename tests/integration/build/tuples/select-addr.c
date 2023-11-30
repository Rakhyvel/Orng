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
int64_t _84_main(void);

/* Function definitions */
int64_t _84_main(void) {
    int64_t _84_t1;
    int64_t _84_t2;
    struct0 _85_x;
    struct0* _84_t4;
    struct0* _84_t5;
    int64_t _84_$retval;
    _84_t1 = 1;
    _84_t2 = 2;
    _85_x = (struct0) {_84_t1, _84_t2};
    _84_t4 = &_85_x;
    (*_84_t4)._0 = 76;
    _84_t5 = &_85_x;
    _84_$retval = (*_84_t5)._0;
    return _84_$retval;
}

int main(void) {
  printf("%ld",_84_main());
  return 0;
}
