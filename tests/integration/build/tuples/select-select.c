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
int64_t _1538_main(void);

/* Function definitions */
int64_t _1538_main(void){
    int64_t _1538_t2;
    int64_t _1538_t3;
    struct struct0 _1538_t1;
    int64_t _1538_t5;
    int64_t _1538_t6;
    struct struct0 _1538_t4;
    struct struct1 _1539_x;
    int64_t _1538_$retval;
    _1538_t2 = 1;
    _1538_t3 = 2;
    _1538_t1 = (struct struct0) {_1538_t2, _1538_t3};
    _1538_t5 = 3;
    _1538_t6 = 4;
    _1538_t4 = (struct struct0) {_1538_t5, _1538_t6};
    _1539_x = (struct struct1) {_1538_t1, _1538_t4};
    _1539_x._0._0 = 77;
    _1538_$retval = _1539_x._0._0;
    return _1538_$retval;
}

int main(void) {
  printf("%ld",_1538_main());
  return 0;
}
