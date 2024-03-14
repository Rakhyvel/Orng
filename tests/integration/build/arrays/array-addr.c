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
int64_t _16_main(void);


/* Function definitions */
int64_t _16_main(void){
    int64_t _17_a;
    int64_t _17_b;
    int64_t _17_c;
    int64_t _17_d;
    int64_t* _16_t9;
    int64_t* _16_t10;
    int64_t* _16_t11;
    int64_t* _16_t12;
    struct struct0 _17_x;
    int64_t _16_t15;
    int64_t _16_t16;
    int64_t _16_t17;
    int64_t _16_t18;
    int64_t _16_$retval;
    _17_a = 1;
    _17_b = 2;
    _17_c = 3;
    _17_d = 4;
    _16_t9 = &_17_a;
    _16_t10 = &_17_b;
    _16_t11 = &_17_c;
    _16_t12 = &_17_d;
    _17_x = (struct struct0) {_16_t9, _16_t10, _16_t11, _16_t12};
    _16_t15 = 2;
    _16_t16 = 4;
    $bounds_check(_16_t15, _16_t16, "tests/integration/arrays/array-addr.orng:8:15:\n    x[2]^ = 71\n             ^");
    **((int64_t**)&_17_x + _16_t15) = 71;
    _16_t17 = 2;
    _16_t18 = 4;
    $bounds_check(_16_t17, _16_t18, "tests/integration/arrays/array-addr.orng:2:3:\nfn main() -> Int {\n ^");
    _16_$retval = **((int64_t**)&_17_x + _16_t17);
    return _16_$retval;
}


int main(void) {
  printf("%ld",_16_main());
  return 0;
}
