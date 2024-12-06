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
int64_t _1884_main(void);


/* Function definitions */
int64_t _1884_main(void){
    int64_t _1884_t1;
    int64_t _1884_t2;
    struct struct0 _1885_x;
    int64_t _1884_$retval;
    _1884_t1 = 20;
    _1884_t2 = 3;
    _1885_x = (struct struct0) {_1884_t1, _1884_t2};
    _1884_$retval = $mult_int64_t(_1885_x._0, _1885_x._1, "tests/integration/tuples/named-field.orng:4:10:\n    x.a * x.b\n        ^");
    return _1884_$retval;
}


int main(void) {
  printf("%ld",_1884_main());
  return 0;
}
