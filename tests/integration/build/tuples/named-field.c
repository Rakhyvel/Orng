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
int64_t _1867_main(void);


/* Function definitions */
int64_t _1867_main(void){
    int64_t _1867_t1;
    int64_t _1867_t2;
    struct struct0 _1868_x;
    int64_t _1867_$retval;
    _1867_t1 = 20;
    _1867_t2 = 3;
    _1868_x = (struct struct0) {_1867_t1, _1867_t2};
    _1867_$retval = $mult_int64_t(_1868_x._0, _1868_x._1, "tests/integration/tuples/named-field.orng:4:10:\n    x.a * x.b\n        ^");
    return _1867_$retval;
}


int main(void) {
  printf("%ld",_1867_main());
  return 0;
}
