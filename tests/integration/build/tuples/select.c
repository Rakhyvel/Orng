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
int64_t _1645_main(void);


/* Function definitions */
int64_t _1645_main(void){
    int64_t _1645_t1;
    int64_t _1645_t2;
    struct struct0 _1646_x;
    int64_t _1645_$retval;
    _1645_t1 = 50;
    _1645_t2 = 5;
    _1646_x = (struct struct0) {_1645_t1, _1645_t2};
    _1645_$retval = $add_int64_t(_1646_x._0, _1646_x._1, "tests/integration/tuples/select.orng:4:10:\n    x.a + x.b\n        ^");
    return _1645_$retval;
}


int main(void) {
  printf("%ld",_1645_main());
  return 0;
}
