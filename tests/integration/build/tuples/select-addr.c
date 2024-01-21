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
int64_t _1564_main(void);

/* Function definitions */
int64_t _1564_main(void){
    int64_t _1564_t1;
    int64_t _1564_t2;
    struct struct0 _1565_x;
    struct struct0* _1564_t4;
    struct struct0* _1564_t5;
    int64_t _1564_$retval;
    _1564_t1 = 1;
    _1564_t2 = 2;
    _1565_x = (struct struct0) {_1564_t1, _1564_t2};
    _1564_t4 = &_1565_x;
    (*_1564_t4)._0 = 76;
    _1564_t5 = &_1565_x;
    _1564_$retval = (*_1564_t5)._0;
    return _1564_$retval;
}

int main(void) {
  printf("%ld",_1564_main());
  return 0;
}
