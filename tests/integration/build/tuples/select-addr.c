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
int64_t _1670_main(void);

/* Function definitions */
int64_t _1670_main(void){
    int64_t _1670_t1;
    int64_t _1670_t2;
    struct0 _1671_x;
    struct0* _1670_t4;
    struct0* _1670_t5;
    int64_t _1670_$retval;
    _1670_t1 = 1;
    _1670_t2 = 2;
    _1671_x = (struct0) {_1670_t1, _1670_t2};
    _1670_t4 = &_1671_x;
    (*_1670_t4)._0 = 76;
    _1670_t5 = &_1671_x;
    _1670_$retval = (*_1670_t5)._0;
    return _1670_$retval;
}

int main(void) {
  printf("%ld",_1670_main());
  return 0;
}
