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
int64_t _1571_main(void);

/* Function definitions */
int64_t _1571_main(void){
    int64_t _1571_t2;
    int64_t _1571_t3;
    struct struct0 _1571_t1;
    int64_t _1571_t5;
    int64_t _1571_t6;
    struct struct0 _1571_t4;
    struct struct1 _1572_x;
    int64_t _1571_$retval;
    _1571_t2 = 1;
    _1571_t3 = 2;
    _1571_t1 = (struct struct0) {_1571_t2, _1571_t3};
    _1571_t5 = 3;
    _1571_t6 = 4;
    _1571_t4 = (struct struct0) {_1571_t5, _1571_t6};
    _1572_x = (struct struct1) {_1571_t1, _1571_t4};
    _1572_x._0._0 = 77;
    _1571_$retval = _1572_x._0._0;
    return _1571_$retval;
}

int main(void) {
  printf("%ld",_1571_main());
  return 0;
}
