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
int64_t _1680_main(void);


/* Function definitions */
int64_t _1680_main(void){
    int64_t _1680_t1;
    int64_t _1680_t2;
    struct struct0 _1681_x;
    struct struct0* _1681_y;
    int64_t _1680_$retval;
    _1680_t1 = 11;
    _1680_t2 = 11;
    _1681_x = (struct struct0) {_1680_t1, _1680_t2};
    _1681_y = &_1681_x;
    (*_1681_y)._0 = 50;
    _1680_$retval = $add_int64_t((*_1681_y)._0, (*_1681_y)._1, "tests/integration/tuples/implicit-deref.orng:6:10:\n    y.a + y.b\n        ^");
    return _1680_$retval;
}


int main(void) {
  printf("%ld",_1680_main());
  return 0;
}
