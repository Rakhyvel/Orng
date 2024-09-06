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
int64_t _1103_main(void);
int64_t _1105_f(void);


/* Function definitions */
int64_t _1103_main(void){
    int64_t _1103_t1;
    int64_t _1103_t2;
    int64_t _1103_t3;
    int64_t _1103_t4;
    struct struct0 _1104_x;
    function1 _1103_t6;
    int64_t _1103_t7;
    int64_t _1103_t8;
    int64_t _1103_$retval;
    _1103_t1 = 0;
    _1103_t2 = 0;
    _1103_t3 = 0;
    _1103_t4 = 0;
    _1104_x = (struct struct0) {_1103_t1, _1103_t2, _1103_t3, _1103_t4};
    _1103_t6 = (function1) _1105_f;
    $lines[$line_idx++] = "tests/integration/lint/array-neg-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _1103_t7 = _1103_t6();
    $line_idx--;
    _1103_t8 = 4;
    $bounds_check(_1103_t7, _1103_t8, "tests/integration/lint/array-neg-bounds-check.orng:2:8:\nfn main() -> Int {\n      ^");
    _1103_$retval = *((int64_t*)&_1104_x + _1103_t7);
    return _1103_$retval;
}

int64_t _1105_f(void){
    int64_t _1105_$retval;
    _1105_$retval = -100;
    return _1105_$retval;
}


int main(void) {
  printf("%ld",_1103_main());
  return 0;
}
