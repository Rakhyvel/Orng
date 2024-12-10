/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
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
int64_t _1170_main(void);
int64_t _1172_f(void);


/* Function definitions */
int64_t _1170_main(void){
    int64_t _1170_t1;
    int64_t _1170_t2;
    int64_t _1170_t3;
    int64_t _1170_t4;
    struct struct0 _1171_x;
    int64_t _1170_t7;
    int64_t _1170_t8;
    int64_t* _1170_t9;
    int64_t _1170_t10;
    struct struct1 _1171_y;
    function2 _1170_t12;
    int64_t _1170_t13;
    int64_t _1170_$retval;
    _1170_t1 = 0;
    _1170_t2 = 0;
    _1170_t3 = 0;
    _1170_t4 = 0;
    _1171_x = (struct struct0) {_1170_t1, _1170_t2, _1170_t3, _1170_t4};
    _1170_t7 = 0;
    _1170_t8 = 4;
    $bounds_check(_1170_t7, _1170_t8, "tests/integration/lint/slice-neg-bounds-check.orng:4:16:\n    let y = []x\n              ^");
    _1170_t9 = ((int64_t*)&_1171_x + _1170_t7);
    _1170_t10 = 4;
    _1171_y = (struct struct1) {_1170_t9, _1170_t10};
    _1170_t12 = (function2) _1172_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-neg-bounds-check.orng:5:9:\n    y[f()]\n       ^";
    _1170_t13 = _1170_t12();
    $line_idx--;
    $bounds_check(_1170_t13, _1171_y._1, "tests/integration/lint/slice-neg-bounds-check.orng:2:8:\nfn main() -> Int {\n      ^");
    _1170_$retval = *((int64_t*)_1171_y._0 + _1170_t13);
    return _1170_$retval;
}

int64_t _1172_f(void){
    int64_t _1172_$retval;
    _1172_$retval = -100;
    return _1172_$retval;
}


int main(void) {
  printf("%ld",_1170_main());
  return 0;
}
