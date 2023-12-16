/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
} struct0;

/* Function forward definitions */
int64_t _10_add(int64_t _10_a,int64_t _10_b);
int64_t _2_main(void);

/* Function definitions */
int64_t _10_add(int64_t _10_a,int64_t _10_b){
    int64_t _10_$retval;
    _10_$retval = $add_int64_t(_10_a, _10_b, "tests/integration/comptime/array-size.orng:12:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _10_$retval;
}

int64_t _2_main(void){
    int64_t _2_t1;
    int64_t _2_t2;
    int64_t _2_t3;
    int64_t _2_t4;
    struct0 _3_x;
    int64_t _2_t8;
    int64_t _2_t12;
    int64_t _2_t16;
    int64_t _2_t20;
    int64_t _2_t21;
    int64_t _2_t22;
    int64_t _2_t23;
    int64_t _2_t24;
    int64_t _2_t25;
    int64_t _2_t26;
    int64_t _2_$retval;
    _2_t1 = 0;
    _2_t2 = 0;
    _2_t3 = 0;
    _2_t4 = 0;
    _3_x = (struct0) {_2_t1, _2_t2, _2_t3, _2_t4};
    _2_t8 = 3;
    *((int64_t*)&_3_x + _2_t8) = 0;
    _2_t12 = 2;
    *((int64_t*)&_3_x + _2_t12) = 200;
    _2_t16 = 1;
    *((int64_t*)&_3_x + _2_t16) = 40;
    _2_t20 = 0;
    *((int64_t*)&_3_x + _2_t20) = 6;
    _2_t21 = 0;
    _2_t22 = 1;
    _2_t23 = $add_int64_t(*((int64_t*)&_3_x + _2_t21), *((int64_t*)&_3_x + _2_t22), "tests/integration/comptime/array-size.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _2_t24 = 2;
    _2_t25 = $add_int64_t(_2_t23, *((int64_t*)&_3_x + _2_t24), "tests/integration/comptime/array-size.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _2_t26 = 3;
    _2_$retval = $add_int64_t(_2_t25, *((int64_t*)&_3_x + _2_t26), "tests/integration/comptime/array-size.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _2_$retval;
}

int main(void) {
  printf("%ld",_2_main());
  return 0;
}
