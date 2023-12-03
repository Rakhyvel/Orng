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
int64_t _1117_main(void);

/* Function definitions */
int64_t _1117_main(void) {
    int64_t _1117_t1;
    int64_t _1117_t2;
    struct0 _1118_x;
    struct0* _1118_y;
    int64_t _1117_$retval;
    _1117_t1 = 11;
    _1117_t2 = 11;
    _1118_x = (struct0) {_1117_t1, _1117_t2};
    _1118_y = &_1118_x;
    (*_1118_y)._0 = 50;
    _1117_$retval = $add_int64_t((*_1118_y)._0, (*_1118_y)._1, "tests/integration/tuples/implicit-deref.orng:6:10:\n    y.a + y.b\n        ^");
    return _1117_$retval;
}

int main(void) {
  printf("%ld",_1117_main());
  return 0;
}
