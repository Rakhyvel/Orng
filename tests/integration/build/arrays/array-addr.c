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
int64_t _21_main(void);


/* Function definitions */
int64_t _21_main(void){
    int64_t _22_a;
    int64_t _22_b;
    int64_t _22_c;
    int64_t _22_d;
    int64_t* _21_t9;
    int64_t* _21_t10;
    int64_t* _21_t11;
    int64_t* _21_t12;
    struct struct0 _22_x;
    int64_t _21_t15;
    int64_t _21_t16;
    int64_t _21_t17;
    int64_t _21_t18;
    int64_t _21_$retval;
    _22_a = 1;
    _22_b = 2;
    _22_c = 3;
    _22_d = 4;
    _21_t9 = &_22_a;
    _21_t10 = &_22_b;
    _21_t11 = &_22_c;
    _21_t12 = &_22_d;
    _22_x = (struct struct0) {_21_t9, _21_t10, _21_t11, _21_t12};
    _21_t15 = 2;
    _21_t16 = 4;
    $bounds_check(_21_t15, _21_t16, "tests/integration/arrays/array-addr.orng:8:15:\n    x[2]^ = 71\n             ^");
    **((int64_t**)&_22_x + _21_t15) = 71;
    _21_t17 = 2;
    _21_t18 = 4;
    $bounds_check(_21_t17, _21_t18, "tests/integration/arrays/array-addr.orng:2:8:\nfn main() -> Int {\n      ^");
    _21_$retval = **((int64_t**)&_22_x + _21_t17);
    return _21_$retval;
}


int main(void) {
  printf("%ld",_21_main());
  return 0;
}
