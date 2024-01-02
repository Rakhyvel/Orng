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
int64_t _1493_main(void);

/* Function definitions */
int64_t _1493_main(void){
    int64_t _1493_t1;
    int64_t _1493_t4;
    struct struct0 _1494_x;
    struct struct0* _1494_y;
    int64_t _1493_$retval;
    _1493_t1 = 19;
    _1493_t4 = 39;
    _1494_x = (struct struct0) {_1493_t1, _1493_t4};
    _1494_y = &_1494_x;
    _1493_$retval = $add_int64_t((*_1494_y)._0, (*_1494_y)._1, "tests/integration/tuples/addr-tuple.orng:5:11:\n    y^.a + y^.b\n         ^");
    return _1493_$retval;
}

int main(void) {
  printf("%ld",_1493_main());
  return 0;
}
