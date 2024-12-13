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
int64_t _25_main(void);


/* Function definitions */
int64_t _25_main(void){
    int64_t _26_a;
    int64_t _26_b;
    int64_t _26_c;
    int64_t _26_d;
    int64_t* _25_t9;
    int64_t* _25_t10;
    int64_t* _25_t11;
    int64_t* _25_t12;
    struct struct0 _26_x;
    int64_t _25_t15;
    int64_t _25_t16;
    int64_t _25_t17;
    int64_t _25_t18;
    int64_t _25_$retval;
    _26_a = 1;
    _26_b = 2;
    _26_c = 3;
    _26_d = 4;
    _25_t9 = &_26_a;
    _25_t10 = &_26_b;
    _25_t11 = &_26_c;
    _25_t12 = &_26_d;
    _26_x = (struct struct0) {_25_t9, _25_t10, _25_t11, _25_t12};
    _25_t15 = 2;
    _25_t16 = 4;
    $bounds_check(_25_t15, _25_t16, "tests/integration/arrays/array-addr.orng:8:15:\n    x[2]^ = 71\n             ^");
    **((int64_t**)&_26_x + _25_t15) = 71;
    _25_t17 = 2;
    _25_t18 = 4;
    $bounds_check(_25_t17, _25_t18, "tests/integration/arrays/array-addr.orng:2:8:\nfn main() -> Int {\n      ^");
    _25_$retval = **((int64_t**)&_26_x + _25_t17);
    return _25_$retval;
}


int main(void) {
  printf("%ld",_25_main());
  return 0;
}
