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
int64_t _1508_main(void);

/* Function definitions */
int64_t _1508_main(void){
    int64_t _1508_t1;
    int64_t _1508_t2;
    struct struct0 _1509_x;
    struct struct0* _1509_y;
    int64_t _1508_$retval;
    _1508_t1 = 11;
    _1508_t2 = 11;
    _1509_x = (struct struct0) {_1508_t1, _1508_t2};
    _1509_y = &_1509_x;
    (*_1509_y)._0 = 50;
    _1508_$retval = $add_int64_t((*_1509_y)._0, (*_1509_y)._1, "tests/integration/tuples/implicit-deref.orng:6:10:\n    y.a + y.b\n        ^");
    return _1508_$retval;
}

int main(void) {
  printf("%ld",_1508_main());
  return 0;
}
