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
    int64_t _2;
    int64_t _3;
    int64_t _4;
};

/* Function forward definitions */
int64_t _73_main(void);


/* Function definitions */
int64_t _73_main(void){
    int64_t _73_t1;
    int64_t _73_t2;
    int64_t _73_t3;
    int64_t _73_t4;
    int64_t _73_t5;
    struct struct0 _74_x;
    struct struct0* _74_y;
    int64_t _73_t9;
    int64_t _73_t10;
    int64_t _73_t11;
    int64_t _73_$retval;
    _73_t1 = 1;
    _73_t2 = 2;
    _73_t3 = 3;
    _73_t4 = 4;
    _73_t5 = 5;
    _74_x = (struct struct0) {_73_t1, _73_t2, _73_t3, _73_t4, _73_t5};
    _74_y = &_74_x;
    _73_t9 = 2;
    _73_t10 = 5;
    _73_t11 = 77;
    $bounds_check(_73_t9, _73_t10, "tests/integration/arrays/implicit-deref.orng:5:11:\n    y[2] + 77\n         ^");
    _73_$retval = $add_int64_t(*((int64_t*)_74_y + _73_t9), _73_t11, "tests/integration/arrays/implicit-deref.orng:5:11:\n    y[2] + 77\n         ^");
    return _73_$retval;
}


int main(void) {
  printf("%ld",_73_main());
  return 0;
}
