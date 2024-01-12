/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function2)(void);

/* Function forward definitions */
int64_t _1066_main(void);
int64_t _1068_f(void);

/* Function definitions */
int64_t _1066_main(void){
    int64_t _1066_t1;
    int64_t _1066_t2;
    int64_t _1066_t3;
    int64_t _1066_t4;
    struct struct0 _1067_x;
    int64_t _1066_t6;
    int64_t _1066_t7;
    int64_t* _1066_t8;
    int64_t _1066_t9;
    struct struct1 _1067_y;
    function2 _1066_t10;
    int64_t _1066_t11;
    int64_t _1066_$retval;
    _1066_t1 = 0;
    _1066_t2 = 0;
    _1066_t3 = 0;
    _1066_t4 = 0;
    _1067_x = (struct struct0) {_1066_t1, _1066_t2, _1066_t3, _1066_t4};
    _1066_t6 = 0;
    _1066_t7 = 4;
    $bounds_check(_1066_t6, _1066_t7, "tests/integration/lint/slice-neg-bounds-check.orng:4:16:\n    let y = []x\n              ^");
    _1066_t8 = ((int64_t*)&_1067_x + _1066_t6);
    _1066_t9 = 4;
    _1067_y = (struct struct1) {_1066_t8, _1066_t9};
    _1066_t10 = _1068_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-neg-bounds-check.orng:5:9:\n    y[f()]\n       ^";
    _1066_t11 = _1066_t10();
    $line_idx--;
    $bounds_check(_1066_t11, _1067_y._1, "tests/integration/lint/slice-neg-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1066_$retval = *((int64_t*)_1067_y._0 + _1066_t11);
    return _1066_$retval;
}

int64_t _1068_f(void){
    int64_t _1068_$retval;
    _1068_$retval = -100;
    return _1068_$retval;
}

int main(void) {
  printf("%ld",_1066_main());
  return 0;
}
