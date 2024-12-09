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
int64_t _69_main(void);


/* Function definitions */
int64_t _69_main(void){
    int64_t _69_t1;
    int64_t _69_t2;
    int64_t _69_t3;
    int64_t _69_t4;
    int64_t _69_t5;
    struct struct0 _70_x;
    struct struct0* _70_y;
    int64_t _69_t9;
    int64_t _69_t10;
    int64_t _69_t11;
    int64_t _69_$retval;
    _69_t1 = 1;
    _69_t2 = 2;
    _69_t3 = 3;
    _69_t4 = 4;
    _69_t5 = 5;
    _70_x = (struct struct0) {_69_t1, _69_t2, _69_t3, _69_t4, _69_t5};
    _70_y = &_70_x;
    _69_t9 = 2;
    _69_t10 = 5;
    _69_t11 = 77;
    $bounds_check(_69_t9, _69_t10, "tests/integration/arrays/implicit-deref.orng:5:11:\n    y[2] + 77\n         ^");
    _69_$retval = $add_int64_t(*((int64_t*)_70_y + _69_t9), _69_t11, "tests/integration/arrays/implicit-deref.orng:5:11:\n    y[2] + 77\n         ^");
    return _69_$retval;
}


int main(void) {
  printf("%ld",_69_main());
  return 0;
}
