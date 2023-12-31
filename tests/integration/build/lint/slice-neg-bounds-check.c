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
int64_t _1048_main(void);
int64_t _1050_f(void);

/* Function definitions */
int64_t _1048_main(void){
    int64_t _1048_t1;
    int64_t _1048_t2;
    int64_t _1048_t3;
    int64_t _1048_t4;
    struct struct0 _1049_x;
    int64_t _1048_t6;
    int64_t _1048_t7;
    int64_t* _1048_t8;
    int64_t _1048_t9;
    struct struct1 _1049_y;
    function2 _1048_t10;
    int64_t _1048_t11;
    int64_t _1048_$retval;
    _1048_t1 = 0;
    _1048_t2 = 0;
    _1048_t3 = 0;
    _1048_t4 = 0;
    _1049_x = (struct struct0) {_1048_t1, _1048_t2, _1048_t3, _1048_t4};
    _1048_t6 = 0;
    _1048_t7 = 4;
    $bounds_check(_1048_t6, _1048_t7, "tests/integration/lint/slice-neg-bounds-check.orng:4:16:\n    let y = []x\n              ^");
    _1048_t8 = ((int64_t*)&_1049_x + _1048_t6);
    _1048_t9 = 4;
    _1049_y = (struct struct1) {_1048_t8, _1048_t9};
    _1048_t10 = _1050_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-neg-bounds-check.orng:5:9:\n    y[f()]\n       ^";
    _1048_t11 = _1048_t10();
    $line_idx--;
    $bounds_check(_1048_t11, _1049_y._1, "tests/integration/lint/slice-neg-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1048_$retval = *((int64_t*)_1049_y._0 + _1048_t11);
    return _1048_$retval;
}

int64_t _1050_f(void){
    int64_t _1050_$retval;
    _1050_$retval = -100;
    return _1050_$retval;
}

int main(void) {
  printf("%ld",_1048_main());
  return 0;
}
