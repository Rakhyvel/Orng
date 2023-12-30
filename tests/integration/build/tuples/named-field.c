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
int64_t _1515_main(void);

/* Function definitions */
int64_t _1515_main(void){
    int64_t _1515_t1;
    int64_t _1515_t2;
    struct0 _1516_x;
    int64_t _1515_$retval;
    _1515_t1 = 20;
    _1515_t2 = 3;
    _1516_x = (struct0) {_1515_t1, _1515_t2};
    _1515_$retval = $mult_int64_t(_1516_x._0, _1516_x._1, "tests/integration/tuples/named-field.orng:4:10:\n    x.a * x.b\n        ^");
    return _1515_$retval;
}

int main(void) {
  printf("%ld",_1515_main());
  return 0;
}
