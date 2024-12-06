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
int64_t _1104_main(void);
int64_t _1106_f(void);


/* Function definitions */
int64_t _1104_main(void){
    int64_t _1104_t1;
    int64_t _1104_t2;
    int64_t _1104_t3;
    int64_t _1104_t4;
    struct struct0 _1105_x;
    function1 _1104_t7;
    int64_t _1104_t8;
    int64_t _1104_t9;
    int64_t _1104_$retval;
    _1104_t1 = 0;
    _1104_t2 = 0;
    _1104_t3 = 0;
    _1104_t4 = 0;
    _1105_x = (struct struct0) {_1104_t1, _1104_t2, _1104_t3, _1104_t4};
    _1104_t7 = (function1) _1106_f;
    $lines[$line_idx++] = "tests/integration/lint/array-copy-neg-bounds-check.orng:4:9:\n    x[f()] = 0\n       ^";
    _1104_t8 = _1104_t7();
    $line_idx--;
    _1104_t9 = 4;
    $bounds_check(_1104_t8, _1104_t9, "tests/integration/lint/array-copy-neg-bounds-check.orng:4:15:\n    x[f()] = 0\n             ^");
    *((int64_t*)&_1105_x + _1104_t8) = 0;
    _1104_$retval = 0;
    return _1104_$retval;
}

int64_t _1106_f(void){
    int64_t _1106_$retval;
    _1106_$retval = -100;
    return _1106_$retval;
}


int main(void) {
  printf("%ld",_1104_main());
  return 0;
}
