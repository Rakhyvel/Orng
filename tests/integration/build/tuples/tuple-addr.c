/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t* _0;
    int64_t* _1;
};

/* Function forward definitions */
int64_t _1832_main(void);


/* Function definitions */
int64_t _1832_main(void){
    int64_t _1833_x;
    int64_t _1833_y;
    int64_t* _1832_t5;
    int64_t* _1832_t6;
    struct struct0 _1833_z;
    int64_t _1832_$retval;
    _1833_x = 30;
    _1833_y = 29;
    _1832_t5 = &_1833_x;
    _1832_t6 = &_1833_y;
    _1833_z = (struct struct0) {_1832_t5, _1832_t6};
    _1832_$retval = $add_int64_t(*_1833_z._0, *_1833_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1832_$retval;
}


int main(void) {
  printf("%ld",_1832_main());
  return 0;
}
