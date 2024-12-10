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
int64_t _1165_main(void);
int64_t _1167_f(void);


/* Function definitions */
int64_t _1165_main(void){
    int64_t _1165_t1;
    int64_t _1165_t2;
    int64_t _1165_t3;
    int64_t _1165_t4;
    struct struct0 _1166_x;
    int64_t _1165_t7;
    int64_t _1165_t8;
    int64_t* _1165_t9;
    int64_t _1165_t10;
    struct struct1 _1166_y;
    function2 _1165_t13;
    int64_t _1165_t14;
    int64_t _1165_$retval;
    _1165_t1 = 0;
    _1165_t2 = 0;
    _1165_t3 = 0;
    _1165_t4 = 0;
    _1166_x = (struct struct0) {_1165_t1, _1165_t2, _1165_t3, _1165_t4};
    _1165_t7 = 0;
    _1165_t8 = 4;
    $bounds_check(_1165_t7, _1165_t8, "tests/integration/lint/slice-copy-pos-bounds-check.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1165_t9 = ((int64_t*)&_1166_x + _1165_t7);
    _1165_t10 = 4;
    _1166_y = (struct struct1) {_1165_t9, _1165_t10};
    _1165_t13 = (function2) _1167_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-pos-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _1165_t14 = _1165_t13();
    $line_idx--;
    $bounds_check(_1165_t14, _1166_y._1, "tests/integration/lint/slice-copy-pos-bounds-check.orng:5:15:\n    y[f()] = 0\n             ^");
    *((int64_t*)_1166_y._0 + _1165_t14) = 0;
    _1165_$retval = 0;
    return _1165_$retval;
}

int64_t _1167_f(void){
    int64_t _1167_$retval;
    _1167_$retval = 100;
    return _1167_$retval;
}


int main(void) {
  printf("%ld",_1165_main());
  return 0;
}
