/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t* _0;
    int64_t* _1;
} struct0;

/* Function forward definitions */
int64_t _1698_main(void);

/* Function definitions */
int64_t _1698_main(void){
    int64_t _1699_x;
    int64_t _1699_y;
    int64_t* _1698_t3;
    int64_t* _1698_t4;
    struct0 _1699_z;
    int64_t _1698_$retval;
    _1699_x = 30;
    _1699_y = 29;
    _1698_t3 = &_1699_x;
    _1698_t4 = &_1699_y;
    _1699_z = (struct0) {_1698_t3, _1698_t4};
    _1698_$retval = $add_int64_t(*_1699_z._0, *_1699_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1698_$retval;
}

int main(void) {
  printf("%ld",_1698_main());
  return 0;
}
