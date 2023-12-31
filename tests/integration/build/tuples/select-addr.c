/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1528_main(void);

/* Function definitions */
int64_t _1528_main(void){
    int64_t _1528_t1;
    int64_t _1528_t2;
    struct struct0 _1529_x;
    struct struct0* _1528_t4;
    struct struct0* _1528_t5;
    int64_t _1528_$retval;
    _1528_t1 = 1;
    _1528_t2 = 2;
    _1529_x = (struct struct0) {_1528_t1, _1528_t2};
    _1528_t4 = &_1529_x;
    (*_1528_t4)._0 = 76;
    _1528_t5 = &_1529_x;
    _1528_$retval = (*_1528_t5)._0;
    return _1528_$retval;
}

int main(void) {
  printf("%ld",_1528_main());
  return 0;
}
