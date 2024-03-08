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
int64_t _1075_main(void);
int64_t _1077_f(void);


/* Function definitions */
int64_t _1075_main(void){
    int64_t _1075_t1;
    int64_t _1075_t2;
    int64_t _1075_t3;
    int64_t _1075_t4;
    struct struct0 _1076_x;
    function1 _1075_t5;
    int64_t _1075_t6;
    int64_t _1075_t7;
    int64_t _1075_$retval;
    _1075_t1 = 0;
    _1075_t2 = 0;
    _1075_t3 = 0;
    _1075_t4 = 0;
    _1076_x = (struct struct0) {_1075_t1, _1075_t2, _1075_t3, _1075_t4};
    _1075_t5 = (function1) _1077_f;
    $lines[$line_idx++] = "tests/integration/lint/array-pos-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _1075_t6 = _1075_t5();
    $line_idx--;
    _1075_t7 = 4;
    $bounds_check(_1075_t6, _1075_t7, "tests/integration/lint/array-pos-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1075_$retval = *((int64_t*)&_1076_x + _1075_t6);
    return _1075_$retval;
}

int64_t _1077_f(void){
    int64_t _1077_$retval;
    _1077_$retval = 100;
    return _1077_$retval;
}


int main(void) {
  printf("%ld",_1075_main());
  return 0;
}
