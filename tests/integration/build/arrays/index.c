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
int64_t _80_main(void);
struct struct2 _82_get_array(int64_t _82_a, int64_t _82_b);


/* Function definitions */
int64_t _80_main(void){
    function0 _80_t0;
    int64_t _80_t2;
    int64_t _80_t3;
    struct struct2 _80_t1;
    struct struct2 _81_x;
    int64_t _80_t5;
    int64_t _80_t6;
    int64_t _80_t7;
    int64_t _80_t8;
    int64_t _80_t9;
    int64_t _80_t10;
    int64_t _80_t11;
    int64_t _80_t12;
    int64_t _80_t13;
    int64_t _80_t14;
    int64_t _80_$retval;
    _80_t0 = (function0) _82_get_array;
    _80_t2 = 15;
    _80_t3 = 16;
    $lines[$line_idx++] = "tests/integration/arrays/index.orng:3:32:\n    let x: [4]Int  = get_array(15, 16)\n                              ^";
    _80_t1 = _80_t0(_80_t2, _80_t3);
    $line_idx--;
    _81_x = _80_t1;
    _80_t5 = 0;
    _80_t6 = 4;
    _80_t7 = 1;
    _80_t8 = 4;
    $bounds_check(_80_t5, _80_t6, "tests/integration/arrays/index.orng:4:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    $bounds_check(_80_t7, _80_t8, "tests/integration/arrays/index.orng:4:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _80_t9 = $add_int64_t(*((int64_t*)&_81_x + _80_t5), *((int64_t*)&_81_x + _80_t7), "tests/integration/arrays/index.orng:4:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _80_t10 = 2;
    _80_t11 = 4;
    $bounds_check(_80_t10, _80_t11, "tests/integration/arrays/index.orng:4:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _80_t12 = $add_int64_t(_80_t9, *((int64_t*)&_81_x + _80_t10), "tests/integration/arrays/index.orng:4:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _80_t13 = 3;
    _80_t14 = 4;
    $bounds_check(_80_t13, _80_t14, "tests/integration/arrays/index.orng:4:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    _80_$retval = $add_int64_t(_80_t12, *((int64_t*)&_81_x + _80_t13), "tests/integration/arrays/index.orng:4:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _80_$retval;
}

struct struct2 _82_get_array(int64_t _82_a, int64_t _82_b){
    struct struct2 _82_$retval;
    _82_$retval = (struct struct2) {_82_a, _82_b, _82_a, _82_b};
    return _82_$retval;
}


int main(void) {
  printf("%ld",_80_main());
  return 0;
}
