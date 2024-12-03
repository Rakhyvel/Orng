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
int64_t _1857_main(void);


/* Function definitions */
int64_t _1857_main(void){
    int64_t _1857_t1;
    int64_t _1857_t2;
    struct struct0 _1858_x;
    struct struct0* _1858_y;
    int64_t _1857_$retval;
    _1857_t1 = 11;
    _1857_t2 = 11;
    _1858_x = (struct struct0) {_1857_t1, _1857_t2};
    _1858_y = &_1858_x;
    (*_1858_y)._0 = 50;
    _1857_$retval = $add_int64_t((*_1858_y)._0, (*_1858_y)._1, "tests/integration/tuples/implicit-deref.orng:6:10:\n    y.a + y.b\n        ^");
    return _1857_$retval;
}


int main(void) {
  printf("%ld",_1857_main());
  return 0;
}
