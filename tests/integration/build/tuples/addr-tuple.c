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
int64_t _1726_main(void);

/* Function definitions */
int64_t _1726_main(void){
    int64_t _1726_t1;
    int64_t _1726_t4;
    struct0 _1727_x;
    struct0* _1727_y;
    int64_t _1726_$retval;
    _1726_t1 = 19;
    _1726_t4 = 39;
    _1727_x = (struct0) {_1726_t1, _1726_t4};
    _1727_y = &_1727_x;
    _1726_$retval = $add_int64_t((*_1727_y)._0, (*_1727_y)._1, "tests/integration/tuples/addr-tuple.orng:5:11:\n    y^.a + y^.b\n         ^");
    return _1726_$retval;
}

int main(void) {
  printf("%ld",_1726_main());
  return 0;
}
