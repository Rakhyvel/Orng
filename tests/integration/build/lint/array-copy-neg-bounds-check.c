/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

typedef int64_t(*function1)(void);

/* Function forward definitions */
int64_t _1090_main(void);
int64_t _1092_f(void);


/* Function definitions */
int64_t _1090_main(void){
    int64_t _1090_t1;
    int64_t _1090_t2;
    int64_t _1090_t3;
    int64_t _1090_t4;
    struct struct0 _1091_x;
    function1 _1090_t7;
    int64_t _1090_t8;
    int64_t _1090_t9;
    int64_t _1090_$retval;
    _1090_t1 = 0;
    _1090_t2 = 0;
    _1090_t3 = 0;
    _1090_t4 = 0;
    _1091_x = (struct struct0) {_1090_t1, _1090_t2, _1090_t3, _1090_t4};
    _1090_t7 = (function1) _1092_f;
    $lines[$line_idx++] = "tests/integration/lint/array-copy-neg-bounds-check.orng:4:9:\n    x[f()] = 0\n       ^";
    _1090_t8 = _1090_t7();
    $line_idx--;
    _1090_t9 = 4;
    $bounds_check(_1090_t8, _1090_t9, "tests/integration/lint/array-copy-neg-bounds-check.orng:4:15:\n    x[f()] = 0\n             ^");
    *((int64_t*)&_1091_x + _1090_t8) = 0;
    _1090_$retval = 0;
    return _1090_$retval;
}

int64_t _1092_f(void){
    int64_t _1092_$retval;
    _1092_$retval = -100;
    return _1092_$retval;
}


int main(void) {
  printf("%ld",_1090_main());
  return 0;
}
