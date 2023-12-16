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
int64_t _160_add(int64_t _160_a,int64_t _160_b);
int64_t _152_main(void);

/* Function definitions */
int64_t _160_add(int64_t _160_a,int64_t _160_b){
    int64_t _160_$retval;
    _160_$retval = $add_int64_t(_160_a, _160_b, "tests/integration/comptime/array-size.orng:12:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _160_$retval;
}

int64_t _152_main(void){
    int64_t _152_t1;
    int64_t _152_t2;
    int64_t _152_t3;
    int64_t _152_t4;
    struct0 _153_x;
    int64_t _152_t8;
    int64_t _152_t12;
    int64_t _152_t16;
    int64_t _152_t20;
    int64_t _152_t21;
    int64_t _152_t22;
    int64_t _152_t23;
    int64_t _152_t24;
    int64_t _152_t25;
    int64_t _152_t26;
    int64_t _152_$retval;
    _152_t1 = 0;
    _152_t2 = 0;
    _152_t3 = 0;
    _152_t4 = 0;
    _153_x = (struct0) {_152_t1, _152_t2, _152_t3, _152_t4};
    _152_t8 = 3;
    *((int64_t*)&_153_x + _152_t8) = 0;
    _152_t12 = 2;
    *((int64_t*)&_153_x + _152_t12) = 200;
    _152_t16 = 1;
    *((int64_t*)&_153_x + _152_t16) = 40;
    _152_t20 = 0;
    *((int64_t*)&_153_x + _152_t20) = 6;
    _152_t21 = 0;
    _152_t22 = 1;
    _152_t23 = $add_int64_t(*((int64_t*)&_153_x + _152_t21), *((int64_t*)&_153_x + _152_t22), "tests/integration/comptime/array-size.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _152_t24 = 2;
    _152_t25 = $add_int64_t(_152_t23, *((int64_t*)&_153_x + _152_t24), "tests/integration/comptime/array-size.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _152_t26 = 3;
    _152_$retval = $add_int64_t(_152_t25, *((int64_t*)&_153_x + _152_t26), "tests/integration/comptime/array-size.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _152_$retval;
}

int main(void) {
  printf("%ld",_152_main());
  return 0;
}
