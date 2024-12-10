/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

struct struct2 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

typedef struct struct2(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _82_main(void);
struct struct2 _84_get_array(int64_t _84_a, int64_t _84_b);


/* Function definitions */
int64_t _82_main(void){
    function0 _82_t0;
    int64_t _82_t2;
    int64_t _82_t3;
    struct struct2 _82_t1;
    struct struct2 _83_x;
    int64_t _82_t5;
    int64_t _82_t6;
    int64_t _82_t7;
    int64_t _82_t8;
    int64_t _82_t9;
    int64_t _82_t10;
    int64_t _82_t11;
    int64_t _82_t12;
    int64_t _82_t13;
    int64_t _82_t14;
    int64_t _82_$retval;
    _82_t0 = (function0) _84_get_array;
    _82_t2 = 15;
    _82_t3 = 16;
    $lines[$line_idx++] = "tests/integration/arrays/index.orng:3:32:\n    let x: [4]Int  = get_array(15, 16)\n                              ^";
    _82_t1 = _82_t0(_82_t2, _82_t3);
    $line_idx--;
    _83_x = _82_t1;
    _82_t5 = 0;
    _82_t6 = 4;
    _82_t7 = 1;
    _82_t8 = 4;
    $bounds_check(_82_t5, _82_t6, "tests/integration/arrays/index.orng:4:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    $bounds_check(_82_t7, _82_t8, "tests/integration/arrays/index.orng:4:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _82_t9 = $add_int64_t(*((int64_t*)&_83_x + _82_t5), *((int64_t*)&_83_x + _82_t7), "tests/integration/arrays/index.orng:4:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _82_t10 = 2;
    _82_t11 = 4;
    $bounds_check(_82_t10, _82_t11, "tests/integration/arrays/index.orng:4:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _82_t12 = $add_int64_t(_82_t9, *((int64_t*)&_83_x + _82_t10), "tests/integration/arrays/index.orng:4:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _82_t13 = 3;
    _82_t14 = 4;
    $bounds_check(_82_t13, _82_t14, "tests/integration/arrays/index.orng:4:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    _82_$retval = $add_int64_t(_82_t12, *((int64_t*)&_83_x + _82_t13), "tests/integration/arrays/index.orng:4:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _82_$retval;
}

struct struct2 _84_get_array(int64_t _84_a, int64_t _84_b){
    struct struct2 _84_$retval;
    _84_$retval = (struct struct2) {_84_a, _84_b, _84_a, _84_b};
    return _84_$retval;
}


int main(void) {
  printf("%ld",_82_main());
  return 0;
}
