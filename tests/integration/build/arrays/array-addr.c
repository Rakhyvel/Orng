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
    int64_t* _2;
    int64_t* _3;
};

/* Function forward definitions */
int64_t _23_main(void);


/* Function definitions */
int64_t _23_main(void){
    int64_t _24_a;
    int64_t _24_b;
    int64_t _24_c;
    int64_t _24_d;
    int64_t* _23_t9;
    int64_t* _23_t10;
    int64_t* _23_t11;
    int64_t* _23_t12;
    struct struct0 _24_x;
    int64_t _23_t15;
    int64_t _23_t16;
    int64_t _23_t17;
    int64_t _23_t18;
    int64_t _23_$retval;
    _24_a = 1;
    _24_b = 2;
    _24_c = 3;
    _24_d = 4;
    _23_t9 = &_24_a;
    _23_t10 = &_24_b;
    _23_t11 = &_24_c;
    _23_t12 = &_24_d;
    _24_x = (struct struct0) {_23_t9, _23_t10, _23_t11, _23_t12};
    _23_t15 = 2;
    _23_t16 = 4;
    $bounds_check(_23_t15, _23_t16, "tests/integration/arrays/array-addr.orng:8:15:\n    x[2]^ = 71\n             ^");
    **((int64_t**)&_24_x + _23_t15) = 71;
    _23_t17 = 2;
    _23_t18 = 4;
    $bounds_check(_23_t17, _23_t18, "tests/integration/arrays/array-addr.orng:2:8:\nfn main() -> Int {\n      ^");
    _23_$retval = **((int64_t**)&_24_x + _23_t17);
    return _23_$retval;
}


int main(void) {
  printf("%ld",_23_main());
  return 0;
}
