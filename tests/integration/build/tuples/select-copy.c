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
int64_t _1828_main(void);


/* Function definitions */
int64_t _1828_main(void){
    int64_t _1828_t1;
    int64_t _1828_t2;
    struct struct0 _1829_x;
    int64_t _1828_$retval;
    _1828_t1 = 50;
    _1828_t2 = 5;
    _1829_x = (struct struct0) {_1828_t1, _1828_t2};
    _1829_x._1 = 6;
    _1828_$retval = $add_int64_t(_1829_x._0, _1829_x._1, "tests/integration/tuples/select-copy.orng:5:10:\n    x.a + x.b\n        ^");
    return _1828_$retval;
}


int main(void) {
  printf("%ld",_1828_main());
  return 0;
}
