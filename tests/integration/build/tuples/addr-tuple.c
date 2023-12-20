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
int64_t _1465_main(void);

/* Function definitions */
int64_t _1465_main(void){
    int64_t _1465_t1;
    int64_t _1465_t4;
    struct0 _1466_x;
    struct0* _1466_y;
    int64_t _1465_$retval;
    _1465_t1 = 19;
    _1465_t4 = 39;
    _1466_x = (struct0) {_1465_t1, _1465_t4};
    _1466_y = &_1466_x;
    _1465_$retval = $add_int64_t((*_1466_y)._0, (*_1466_y)._1, "tests/integration/tuples/addr-tuple.orng:5:11:\n    y^.a + y^.b\n         ^");
    return _1465_$retval;
}

int main(void) {
  printf("%ld",_1465_main());
  return 0;
}
