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
int64_t _1050_main(void);
int64_t _1052_f(void);


/* Function definitions */
int64_t _1050_main(void){
    int64_t _1050_t1;
    int64_t _1050_t2;
    int64_t _1050_t3;
    int64_t _1050_t4;
    struct struct0 _1051_x;
    function1 _1050_t6;
    int64_t _1050_t7;
    int64_t _1050_t8;
    int64_t _1050_$retval;
    _1050_t1 = 0;
    _1050_t2 = 0;
    _1050_t3 = 0;
    _1050_t4 = 0;
    _1051_x = (struct struct0) {_1050_t1, _1050_t2, _1050_t3, _1050_t4};
    _1050_t6 = (function1) _1052_f;
    $lines[$line_idx++] = "tests/integration/lint/array-pos-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _1050_t7 = _1050_t6();
    $line_idx--;
    _1050_t8 = 4;
    $bounds_check(_1050_t7, _1050_t8, "tests/integration/lint/array-pos-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1050_$retval = *((int64_t*)&_1051_x + _1050_t7);
    return _1050_$retval;
}

int64_t _1052_f(void){
    int64_t _1052_$retval;
    _1052_$retval = 100;
    return _1052_$retval;
}


int main(void) {
  printf("%ld",_1050_main());
  return 0;
}
