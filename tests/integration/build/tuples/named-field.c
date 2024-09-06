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
int64_t _1825_main(void);


/* Function definitions */
int64_t _1825_main(void){
    int64_t _1825_t1;
    int64_t _1825_t2;
    struct struct0 _1826_x;
    int64_t _1825_$retval;
    _1825_t1 = 20;
    _1825_t2 = 3;
    _1826_x = (struct struct0) {_1825_t1, _1825_t2};
    _1825_$retval = $mult_int64_t(_1826_x._0, _1826_x._1, "tests/integration/tuples/named-field.orng:4:10:\n    x.a * x.b\n        ^");
    return _1825_$retval;
}


int main(void) {
  printf("%ld",_1825_main());
  return 0;
}
