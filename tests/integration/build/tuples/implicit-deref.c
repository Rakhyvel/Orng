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
int64_t _1739_main(void);

/* Function definitions */
int64_t _1739_main(void){
    int64_t _1739_t1;
    int64_t _1739_t2;
    struct0 _1740_x;
    struct0* _1740_y;
    int64_t _1739_$retval;
    _1739_t1 = 11;
    _1739_t2 = 11;
    _1740_x = (struct0) {_1739_t1, _1739_t2};
    _1740_y = &_1740_x;
    (*_1740_y)._0 = 50;
    _1739_$retval = $add_int64_t((*_1740_y)._0, (*_1740_y)._1, "tests/integration/tuples/implicit-deref.orng:6:10:\n    y.a + y.b\n        ^");
    return _1739_$retval;
}

int main(void) {
  printf("%ld",_1739_main());
  return 0;
}
