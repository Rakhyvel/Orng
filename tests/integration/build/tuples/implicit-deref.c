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
int64_t _1722_main(void);

/* Function definitions */
int64_t _1722_main(void){
    int64_t _1722_t1;
    int64_t _1722_t2;
    struct0 _1723_x;
    struct0* _1723_y;
    int64_t _1722_$retval;
    _1722_t1 = 11;
    _1722_t2 = 11;
    _1723_x = (struct0) {_1722_t1, _1722_t2};
    _1723_y = &_1723_x;
    (*_1723_y)._0 = 50;
    _1722_$retval = $add_int64_t((*_1723_y)._0, (*_1723_y)._1, "tests/integration/tuples/implicit-deref.orng:6:10:\n    y.a + y.b\n        ^");
    return _1722_$retval;
}

int main(void) {
  printf("%ld",_1722_main());
  return 0;
}
