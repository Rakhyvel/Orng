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
int64_t _1732_main(void);

/* Function definitions */
int64_t _1732_main(void){
    int64_t _1732_t1;
    int64_t _1732_t2;
    struct0 _1733_x;
    struct0* _1733_y;
    int64_t _1732_$retval;
    _1732_t1 = 11;
    _1732_t2 = 11;
    _1733_x = (struct0) {_1732_t1, _1732_t2};
    _1733_y = &_1733_x;
    (*_1733_y)._0 = 50;
    _1732_$retval = $add_int64_t((*_1733_y)._0, (*_1733_y)._1, "tests/integration/tuples/implicit-deref.orng:6:10:\n    y.a + y.b\n        ^");
    return _1732_$retval;
}

int main(void) {
  printf("%ld",_1732_main());
  return 0;
}
