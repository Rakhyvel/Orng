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
int64_t _135_main(void);


/* Function definitions */
int64_t _135_main(void){
    int64_t _135_t1;
    int64_t _135_t2;
    struct struct0 _136_x;
    int64_t _135_$retval;
    _135_t1 = 240;
    _135_t2 = 5;
    _136_x = (struct struct0) {_135_t1, _135_t2};
    _135_$retval = $add_int64_t(_136_x._0, _136_x._1, "tests/integration/comptime/default-init.orng:4:10:\n    x.a + x.b\n        ^");
    return _135_$retval;
}


int main(void) {
  printf("%ld",_135_main());
  return 0;
}
