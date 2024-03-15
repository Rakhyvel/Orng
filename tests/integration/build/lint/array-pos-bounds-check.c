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
int64_t _1041_main(void);
int64_t _1043_f(void);


/* Function definitions */
int64_t _1041_main(void){
    int64_t _1041_t1;
    int64_t _1041_t2;
    int64_t _1041_t3;
    int64_t _1041_t4;
    struct struct0 _1042_x;
    function1 _1041_t6;
    int64_t _1041_t7;
    int64_t _1041_t8;
    int64_t _1041_$retval;
    _1041_t1 = 0;
    _1041_t2 = 0;
    _1041_t3 = 0;
    _1041_t4 = 0;
    _1042_x = (struct struct0) {_1041_t1, _1041_t2, _1041_t3, _1041_t4};
    _1041_t6 = (function1) _1043_f;
    $lines[$line_idx++] = "tests/integration/lint/array-pos-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _1041_t7 = _1041_t6();
    $line_idx--;
    _1041_t8 = 4;
    $bounds_check(_1041_t7, _1041_t8, "tests/integration/lint/array-pos-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1041_$retval = *((int64_t*)&_1042_x + _1041_t7);
    return _1041_$retval;
}

int64_t _1043_f(void){
    int64_t _1043_$retval;
    _1043_$retval = 100;
    return _1043_$retval;
}


int main(void) {
  printf("%ld",_1041_main());
  return 0;
}
