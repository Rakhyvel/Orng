/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _1479_main(void);

/* Function definitions */
int64_t _1479_main(void){
    int64_t _1479_t1;
    int64_t _1479_t2;
    struct0 _1480_x;
    int64_t _1479_$retval;
    _1479_t1 = 50;
    _1479_t2 = 7;
    _1480_x = (struct0) {_1479_t1, _1479_t2};
    _1479_$retval = $add_int64_t(_1480_x._0, _1480_x._1, "tests/integration/tuples/default-fields.orng:4:10:\n    x.a + x.b\n        ^");
    return _1479_$retval;
}

int main(void) {
  printf("%ld",_1479_main());
  return 0;
}
