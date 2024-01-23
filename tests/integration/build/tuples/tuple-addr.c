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
int64_t _1626_main(void);


/* Function definitions */
int64_t _1626_main(void){
    int64_t _1627_x;
    int64_t _1627_y;
    int64_t* _1626_t3;
    int64_t* _1626_t4;
    struct struct0 _1627_z;
    int64_t _1626_$retval;
    _1627_x = 30;
    _1627_y = 29;
    _1626_t3 = &_1627_x;
    _1626_t4 = &_1627_y;
    _1627_z = (struct struct0) {_1626_t3, _1626_t4};
    _1626_$retval = $add_int64_t(*_1627_z._0, *_1627_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1626_$retval;
}


int main(void) {
  printf("%ld",_1626_main());
  return 0;
}
