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
int64_t _1523_main(void);

/* Function definitions */
int64_t _1523_main(void){
    int64_t _1523_t1;
    int64_t _1523_t2;
    struct struct0 _1524_x;
    int64_t _1523_$retval;
    _1523_t1 = 20;
    _1523_t2 = 3;
    _1524_x = (struct struct0) {_1523_t1, _1523_t2};
    _1523_$retval = $mult_int64_t(_1524_x._0, _1524_x._1, "tests/integration/tuples/named-field.orng:4:10:\n    x.a * x.b\n        ^");
    return _1523_$retval;
}

int main(void) {
  printf("%ld",_1523_main());
  return 0;
}
