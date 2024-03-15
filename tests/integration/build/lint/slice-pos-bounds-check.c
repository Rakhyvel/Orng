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
int64_t _1069_main(void);
int64_t _1071_f(void);


/* Function definitions */
int64_t _1069_main(void){
    int64_t _1069_t1;
    int64_t _1069_t2;
    int64_t _1069_t3;
    int64_t _1069_t4;
    struct struct0 _1070_x;
    int64_t _1069_t7;
    int64_t _1069_t8;
    int64_t* _1069_t9;
    int64_t _1069_t10;
    struct struct1 _1070_y;
    function2 _1069_t12;
    int64_t _1069_t13;
    int64_t _1069_$retval;
    _1069_t1 = 0;
    _1069_t2 = 0;
    _1069_t3 = 0;
    _1069_t4 = 0;
    _1070_x = (struct struct0) {_1069_t1, _1069_t2, _1069_t3, _1069_t4};
    _1069_t7 = 0;
    _1069_t8 = 4;
    $bounds_check(_1069_t7, _1069_t8, "tests/integration/lint/slice-pos-bounds-check.orng:4:16:\n    let y = []x\n              ^");
    _1069_t9 = ((int64_t*)&_1070_x + _1069_t7);
    _1069_t10 = 4;
    _1070_y = (struct struct1) {_1069_t9, _1069_t10};
    _1069_t12 = (function2) _1071_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-pos-bounds-check.orng:5:9:\n    y[f()]\n       ^";
    _1069_t13 = _1069_t12();
    $line_idx--;
    $bounds_check(_1069_t13, _1070_y._1, "tests/integration/lint/slice-pos-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1069_$retval = *((int64_t*)_1070_y._0 + _1069_t13);
    return _1069_$retval;
}

int64_t _1071_f(void){
    int64_t _1071_$retval;
    _1071_$retval = 100;
    return _1071_$retval;
}


int main(void) {
  printf("%ld",_1069_main());
  return 0;
}
