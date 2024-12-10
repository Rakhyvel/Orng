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
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _133_main(void);


/* Function definitions */
int64_t _133_main(void){
    int64_t _133_t1;
    int64_t _133_t2;
    struct struct0 _134_x;
    int64_t _133_$retval;
    _133_t1 = 240;
    _133_t2 = 5;
    _134_x = (struct struct0) {_133_t1, _133_t2};
    _133_$retval = $add_int64_t(_134_x._0, _134_x._1, "tests/integration/comptime/default-init.orng:4:10:\n    x.a + x.b\n        ^");
    return _133_$retval;
}


int main(void) {
  printf("%ld",_133_main());
  return 0;
}
