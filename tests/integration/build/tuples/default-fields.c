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
int64_t _1501_main(void);

/* Function definitions */
int64_t _1501_main(void){
    int64_t _1501_t1;
    int64_t _1501_t2;
    struct struct0 _1502_x;
    int64_t _1501_$retval;
    _1501_t1 = 50;
    _1501_t2 = 7;
    _1502_x = (struct struct0) {_1501_t1, _1501_t2};
    _1501_$retval = $add_int64_t(_1502_x._0, _1502_x._1, "tests/integration/tuples/default-fields.orng:4:10:\n    x.a + x.b\n        ^");
    return _1501_$retval;
}

int main(void) {
  printf("%ld",_1501_main());
  return 0;
}
