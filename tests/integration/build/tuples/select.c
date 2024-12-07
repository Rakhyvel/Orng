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
int64_t _1910_main(void);


/* Function definitions */
int64_t _1910_main(void){
    int64_t _1910_t1;
    int64_t _1910_t2;
    struct struct0 _1911_x;
    int64_t _1910_$retval;
    _1910_t1 = 50;
    _1910_t2 = 5;
    _1911_x = (struct struct0) {_1910_t1, _1910_t2};
    _1910_$retval = $add_int64_t(_1911_x._0, _1911_x._1, "tests/integration/tuples/select.orng:4:10:\n    x.a + x.b\n        ^");
    return _1910_$retval;
}


int main(void) {
  printf("%ld",_1910_main());
  return 0;
}
