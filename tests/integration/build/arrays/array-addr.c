/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t* _0;
    int64_t* _1;
    int64_t* _2;
    int64_t* _3;
} struct0;

/* Function forward definitions */
int64_t _27_main(void);

/* Function definitions */
int64_t _27_main(void){
    int64_t _28_a;
    int64_t _28_b;
    int64_t _28_c;
    int64_t _28_d;
    int64_t* _27_t5;
    int64_t* _27_t6;
    int64_t* _27_t7;
    int64_t* _27_t8;
    struct0 _28_x;
    int64_t _27_t10;
    int64_t _27_t11;
    int64_t _27_t12;
    int64_t _27_t13;
    int64_t _27_$retval;
    _28_a = 1;
    _28_b = 2;
    _28_c = 3;
    _28_d = 4;
    _27_t5 = &_28_a;
    _27_t6 = &_28_b;
    _27_t7 = &_28_c;
    _27_t8 = &_28_d;
    _28_x = (struct0) {_27_t5, _27_t6, _27_t7, _27_t8};
    _27_t10 = 2;
    _27_t11 = 4;
    $bounds_check(_27_t10, _27_t11, "tests/integration/arrays/array-addr.orng:8:15:\n    x[2]^ = 71\n             ^");
    **((int64_t**)&_28_x + _27_t10) = 71;
    _27_t12 = 2;
    _27_t13 = 4;
    $bounds_check(_27_t12, _27_t13, "tests/integration/arrays/array-addr.orng:2:3:\nfn main() -> Int {\n ^");
    _27_$retval = **((int64_t**)&_28_x + _27_t12);
    return _27_$retval;
}

int main(void) {
  printf("%ld",_27_main());
  return 0;
}
