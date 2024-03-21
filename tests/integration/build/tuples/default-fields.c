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
int64_t _1731_main(void);


/* Function definitions */
int64_t _1731_main(void){
    int64_t _1731_t1;
    int64_t _1731_t2;
    struct struct0 _1732_x;
    int64_t _1731_$retval;
    _1731_t1 = 50;
    _1731_t2 = 7;
    _1732_x = (struct struct0) {_1731_t1, _1731_t2};
    _1731_$retval = $add_int64_t(_1732_x._0, _1732_x._1, "tests/integration/tuples/default-fields.orng:4:10:\n    x.a + x.b\n        ^");
    return _1731_$retval;
}


int main(void) {
  printf("%ld",_1731_main());
  return 0;
}
