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
int64_t _1535_main(void);

/* Function definitions */
int64_t _1535_main(void){
    int64_t _1535_t1;
    int64_t _1535_t4;
    struct0 _1536_x;
    struct0* _1536_y;
    int64_t _1535_$retval;
    _1535_t1 = 19;
    _1535_t4 = 39;
    _1536_x = (struct0) {_1535_t1, _1535_t4};
    _1536_y = &_1536_x;
    _1535_$retval = $add_int64_t((*_1536_y)._0, (*_1536_y)._1, "tests/integration/tuples/addr-tuple.orng:5:11:\n    y^.a + y^.b\n         ^");
    return _1535_$retval;
}

int main(void) {
  printf("%ld",_1535_main());
  return 0;
}
