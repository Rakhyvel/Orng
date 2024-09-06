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
int64_t _1832_main(void);


/* Function definitions */
int64_t _1832_main(void){
    int64_t _1832_t1;
    int64_t _1832_t2;
    struct struct0 _1833_x;
    int64_t _1832_$retval;
    _1832_t1 = 20;
    _1832_t2 = 3;
    _1833_x = (struct struct0) {_1832_t1, _1832_t2};
    _1832_$retval = $mult_int64_t(_1833_x._0, _1833_x._1, "tests/integration/tuples/named-field.orng:4:10:\n    x.a * x.b\n        ^");
    return _1832_$retval;
}


int main(void) {
  printf("%ld",_1832_main());
  return 0;
}
