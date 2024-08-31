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
int64_t _1040_main(void);
int64_t _1042_f(void);


/* Function definitions */
int64_t _1040_main(void){
    int64_t _1040_t1;
    int64_t _1040_t2;
    int64_t _1040_t3;
    int64_t _1040_t4;
    struct struct0 _1041_x;
    function1 _1040_t7;
    int64_t _1040_t8;
    int64_t _1040_t9;
    int64_t _1040_$retval;
    _1040_t1 = 0;
    _1040_t2 = 0;
    _1040_t3 = 0;
    _1040_t4 = 0;
    _1041_x = (struct struct0) {_1040_t1, _1040_t2, _1040_t3, _1040_t4};
    _1040_t7 = (function1) _1042_f;
    $lines[$line_idx++] = "tests/integration/lint/array-copy-neg-bounds-check.orng:4:9:\n    x[f()] = 0\n       ^";
    _1040_t8 = _1040_t7();
    $line_idx--;
    _1040_t9 = 4;
    $bounds_check(_1040_t8, _1040_t9, "tests/integration/lint/array-copy-neg-bounds-check.orng:4:15:\n    x[f()] = 0\n             ^");
    *((int64_t*)&_1041_x + _1040_t8) = 0;
    _1040_$retval = 0;
    return _1040_$retval;
}

int64_t _1042_f(void){
    int64_t _1042_$retval;
    _1042_$retval = -100;
    return _1042_$retval;
}


int main(void) {
  printf("%ld",_1040_main());
  return 0;
}
