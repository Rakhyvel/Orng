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
int64_t _1490_main(void);

/* Function definitions */
int64_t _1490_main(void){
    int64_t _1490_t1;
    int64_t _1490_t4;
    struct0 _1491_x;
    struct0* _1491_y;
    int64_t _1490_$retval;
    _1490_t1 = 19;
    _1490_t4 = 39;
    _1491_x = (struct0) {_1490_t1, _1490_t4};
    _1491_y = &_1491_x;
    _1490_$retval = $add_int64_t((*_1491_y)._0, (*_1491_y)._1, "tests/integration/tuples/addr-tuple.orng:5:11:\n    y^.a + y^.b\n         ^");
    return _1490_$retval;
}

int main(void) {
  printf("%ld",_1490_main());
  return 0;
}
