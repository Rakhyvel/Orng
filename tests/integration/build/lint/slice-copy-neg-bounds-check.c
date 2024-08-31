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
int64_t _1068_main(void);
int64_t _1070_f(void);


/* Function definitions */
int64_t _1068_main(void){
    int64_t _1068_t1;
    int64_t _1068_t2;
    int64_t _1068_t3;
    int64_t _1068_t4;
    struct struct0 _1069_x;
    int64_t _1068_t7;
    int64_t _1068_t8;
    int64_t* _1068_t9;
    int64_t _1068_t10;
    struct struct1 _1069_y;
    function2 _1068_t13;
    int64_t _1068_t14;
    int64_t _1068_$retval;
    _1068_t1 = 0;
    _1068_t2 = 0;
    _1068_t3 = 0;
    _1068_t4 = 0;
    _1069_x = (struct struct0) {_1068_t1, _1068_t2, _1068_t3, _1068_t4};
    _1068_t7 = 0;
    _1068_t8 = 4;
    $bounds_check(_1068_t7, _1068_t8, "tests/integration/lint/slice-copy-neg-bounds-check.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1068_t9 = ((int64_t*)&_1069_x + _1068_t7);
    _1068_t10 = 4;
    _1069_y = (struct struct1) {_1068_t9, _1068_t10};
    _1068_t13 = (function2) _1070_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _1068_t14 = _1068_t13();
    $line_idx--;
    $bounds_check(_1068_t14, _1069_y._1, "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:15:\n    y[f()] = 0\n             ^");
    *((int64_t*)_1069_y._0 + _1068_t14) = 0;
    _1068_$retval = 0;
    return _1068_$retval;
}

int64_t _1070_f(void){
    int64_t _1070_$retval;
    _1070_$retval = -100;
    return _1070_$retval;
}


int main(void) {
  printf("%ld",_1068_main());
  return 0;
}
