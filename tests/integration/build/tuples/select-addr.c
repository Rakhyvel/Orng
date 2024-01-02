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
int64_t _1531_main(void);

/* Function definitions */
int64_t _1531_main(void){
    int64_t _1531_t1;
    int64_t _1531_t2;
    struct struct0 _1532_x;
    struct struct0* _1531_t4;
    struct struct0* _1531_t5;
    int64_t _1531_$retval;
    _1531_t1 = 1;
    _1531_t2 = 2;
    _1532_x = (struct struct0) {_1531_t1, _1531_t2};
    _1531_t4 = &_1532_x;
    (*_1531_t4)._0 = 76;
    _1531_t5 = &_1532_x;
    _1531_$retval = (*_1531_t5)._0;
    return _1531_$retval;
}

int main(void) {
  printf("%ld",_1531_main());
  return 0;
}
