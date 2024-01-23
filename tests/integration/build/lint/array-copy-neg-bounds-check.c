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
int64_t _1033_main(void);
int64_t _1035_f(void);


/* Function definitions */
int64_t _1033_main(void){
    int64_t _1033_t1;
    int64_t _1033_t2;
    int64_t _1033_t3;
    int64_t _1033_t4;
    struct struct0 _1034_x;
    function1 _1033_t6;
    int64_t _1033_t7;
    int64_t _1033_t8;
    int64_t _1033_$retval;
    _1033_t1 = 0;
    _1033_t2 = 0;
    _1033_t3 = 0;
    _1033_t4 = 0;
    _1034_x = (struct struct0) {_1033_t1, _1033_t2, _1033_t3, _1033_t4};
    _1033_t6 = _1035_f;
    $lines[$line_idx++] = "tests/integration/lint/array-copy-neg-bounds-check.orng:4:9:\n    x[f()] = 0\n       ^";
    _1033_t7 = _1033_t6();
    $line_idx--;
    _1033_t8 = 4;
    $bounds_check(_1033_t7, _1033_t8, "tests/integration/lint/array-copy-neg-bounds-check.orng:4:15:\n    x[f()] = 0\n             ^");
    *((int64_t*)&_1034_x + _1033_t7) = 0;
    _1033_$retval = 0;
    return _1033_$retval;
}

int64_t _1035_f(void){
    int64_t _1035_$retval;
    _1035_$retval = -100;
    return _1035_$retval;
}


int main(void) {
  printf("%ld",_1033_main());
  return 0;
}
