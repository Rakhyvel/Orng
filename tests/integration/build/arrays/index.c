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
int64_t _75_main(void);
struct struct2 _77_get_array(int64_t _77_a, int64_t _77_b);


/* Function definitions */
int64_t _75_main(void){
    function0 _75_t0;
    int64_t _75_t2;
    int64_t _75_t3;
    struct struct2 _75_t1;
    struct struct2 _76_x;
    int64_t _75_t5;
    int64_t _75_t6;
    int64_t _75_t7;
    int64_t _75_t8;
    int64_t _75_t9;
    int64_t _75_t10;
    int64_t _75_t11;
    int64_t _75_t12;
    int64_t _75_t13;
    int64_t _75_t14;
    int64_t _75_$retval;
    _75_t0 = (function0) _77_get_array;
    _75_t2 = 15;
    _75_t3 = 16;
    $lines[$line_idx++] = "tests/integration/arrays/index.orng:3:32:\n    let x: [4]Int  = get_array(15, 16)\n                              ^";
    _75_t1 = _75_t0(_75_t2, _75_t3);
    $line_idx--;
    _76_x = _75_t1;
    _75_t5 = 0;
    _75_t6 = 4;
    _75_t7 = 1;
    _75_t8 = 4;
    $bounds_check(_75_t5, _75_t6, "tests/integration/arrays/index.orng:4:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    $bounds_check(_75_t7, _75_t8, "tests/integration/arrays/index.orng:4:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _75_t9 = $add_int64_t(*((int64_t*)&_76_x + _75_t5), *((int64_t*)&_76_x + _75_t7), "tests/integration/arrays/index.orng:4:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _75_t10 = 2;
    _75_t11 = 4;
    $bounds_check(_75_t10, _75_t11, "tests/integration/arrays/index.orng:4:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _75_t12 = $add_int64_t(_75_t9, *((int64_t*)&_76_x + _75_t10), "tests/integration/arrays/index.orng:4:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _75_t13 = 3;
    _75_t14 = 4;
    $bounds_check(_75_t13, _75_t14, "tests/integration/arrays/index.orng:4:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    _75_$retval = $add_int64_t(_75_t12, *((int64_t*)&_76_x + _75_t13), "tests/integration/arrays/index.orng:4:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _75_$retval;
}

struct struct2 _77_get_array(int64_t _77_a, int64_t _77_b){
    struct struct2 _77_$retval;
    _77_$retval = (struct struct2) {_77_a, _77_b, _77_a, _77_b};
    return _77_$retval;
}


int main(void) {
  printf("%ld",_75_main());
  return 0;
}
