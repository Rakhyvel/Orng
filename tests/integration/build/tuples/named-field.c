/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1878_main(void);


/* Function definitions */
int64_t _1878_main(void){
    int64_t _1878_t1;
    int64_t _1878_t2;
    struct struct0 _1879_x;
    int64_t _1878_$retval;
    _1878_t1 = 20;
    _1878_t2 = 3;
    _1879_x = (struct struct0) {_1878_t1, _1878_t2};
    _1878_$retval = $mult_int64_t(_1879_x._0, _1879_x._1, "tests/integration/tuples/named-field.orng:4:10:\n    x.a * x.b\n        ^");
    return _1878_$retval;
}


int main(void) {
  printf("%ld",_1878_main());
  return 0;
}
