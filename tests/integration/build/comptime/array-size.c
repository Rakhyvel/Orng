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
int64_t _87_add(int64_t _87_a,int64_t _87_b);
int64_t _85_main(void);

/* Function definitions */
int64_t _87_add(int64_t _87_a,int64_t _87_b) {
    int64_t _87_$retval;
    _87_$retval = $add_int64_t(_87_a, _87_b, "tests/integration/comptime/array-size.orng:12:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _87_$retval;
}

int64_t _85_main(void) {
    int64_t _85_t1;
    int64_t _85_t2;
    int64_t _85_t3;
    int64_t _85_t4;
    struct0 _86_x;
    int64_t _85_t8;
    int64_t _85_t12;
    int64_t _85_t16;
    int64_t _85_t20;
    int64_t _85_t21;
    int64_t _85_t22;
    int64_t _85_t23;
    int64_t _85_t24;
    int64_t _85_t25;
    int64_t _85_t26;
    int64_t _85_$retval;
    _85_t1 = 0;
    _85_t2 = 0;
    _85_t3 = 0;
    _85_t4 = 0;
    _86_x = (struct0) {_85_t1, _85_t2, _85_t3, _85_t4};
    _85_t8 = 3;
    *((int64_t*)&_86_x + _85_t8) = 0;
    _85_t12 = 2;
    *((int64_t*)&_86_x + _85_t12) = 200;
    _85_t16 = 1;
    *((int64_t*)&_86_x + _85_t16) = 40;
    _85_t20 = 0;
    *((int64_t*)&_86_x + _85_t20) = 6;
    _85_t21 = 0;
    _85_t22 = 1;
    _85_t23 = $add_int64_t(*((int64_t*)&_86_x + _85_t21), *((int64_t*)&_86_x + _85_t22), "tests/integration/comptime/array-size.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _85_t24 = 2;
    _85_t25 = $add_int64_t(_85_t23, *((int64_t*)&_86_x + _85_t24), "tests/integration/comptime/array-size.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _85_t26 = 3;
    _85_$retval = $add_int64_t(_85_t25, *((int64_t*)&_86_x + _85_t26), "tests/integration/comptime/array-size.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _85_$retval;
}

int main(void) {
  printf("%ld",_85_main());
  return 0;
}
