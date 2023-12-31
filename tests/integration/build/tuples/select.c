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
int64_t _1538_main(void);

/* Function definitions */
int64_t _1538_main(void){
    int64_t _1538_t1;
    int64_t _1538_t2;
    struct struct0 _1539_x;
    int64_t _1538_$retval;
    _1538_t1 = 50;
    _1538_t2 = 5;
    _1539_x = (struct struct0) {_1538_t1, _1538_t2};
    _1538_$retval = $add_int64_t(_1539_x._0, _1539_x._1, "tests/integration/tuples/select.orng:4:10:\n    x.a + x.b\n        ^");
    return _1538_$retval;
}

int main(void) {
  printf("%ld",_1538_main());
  return 0;
}
