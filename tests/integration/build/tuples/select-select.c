/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    struct struct0 _0;
    struct struct0 _1;
};

/* Function forward definitions */
int64_t _1553_main(void);

/* Function definitions */
int64_t _1553_main(void){
    int64_t _1553_t2;
    int64_t _1553_t3;
    struct struct0 _1553_t1;
    int64_t _1553_t5;
    int64_t _1553_t6;
    struct struct0 _1553_t4;
    struct struct1 _1554_x;
    int64_t _1553_$retval;
    _1553_t2 = 1;
    _1553_t3 = 2;
    _1553_t1 = (struct struct0) {_1553_t2, _1553_t3};
    _1553_t5 = 3;
    _1553_t6 = 4;
    _1553_t4 = (struct struct0) {_1553_t5, _1553_t6};
    _1554_x = (struct struct1) {_1553_t1, _1553_t4};
    _1554_x._0._0 = 77;
    _1553_$retval = _1554_x._0._0;
    return _1553_$retval;
}

int main(void) {
  printf("%ld",_1553_main());
  return 0;
}
