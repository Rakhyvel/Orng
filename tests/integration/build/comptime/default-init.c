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
int64_t _42_main(void);


/* Function definitions */
int64_t _42_main(void){
    int64_t _42_t1;
    int64_t _42_t2;
    struct struct0 _43_x;
    int64_t _42_$retval;
    _42_t1 = 240;
    _42_t2 = 5;
    _43_x = (struct struct0) {_42_t1, _42_t2};
    _42_$retval = $add_int64_t(_43_x._0, _43_x._1, "tests/integration/comptime/default-init.orng:4:10:\n    x.a + x.b\n        ^");
    return _42_$retval;
}


int main(void) {
  printf("%ld",_42_main());
  return 0;
}
