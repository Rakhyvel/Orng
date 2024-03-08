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
int64_t _1070_main(void);
int64_t _1072_f(void);


/* Function definitions */
int64_t _1070_main(void){
    int64_t _1070_t1;
    int64_t _1070_t2;
    int64_t _1070_t3;
    int64_t _1070_t4;
    struct struct0 _1071_x;
    function1 _1070_t5;
    int64_t _1070_t6;
    int64_t _1070_t7;
    int64_t _1070_$retval;
    _1070_t1 = 0;
    _1070_t2 = 0;
    _1070_t3 = 0;
    _1070_t4 = 0;
    _1071_x = (struct struct0) {_1070_t1, _1070_t2, _1070_t3, _1070_t4};
    _1070_t5 = (function1) _1072_f;
    $lines[$line_idx++] = "tests/integration/lint/array-neg-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _1070_t6 = _1070_t5();
    $line_idx--;
    _1070_t7 = 4;
    $bounds_check(_1070_t6, _1070_t7, "tests/integration/lint/array-neg-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1070_$retval = *((int64_t*)&_1071_x + _1070_t6);
    return _1070_$retval;
}

int64_t _1072_f(void){
    int64_t _1072_$retval;
    _1072_$retval = -100;
    return _1072_$retval;
}


int main(void) {
  printf("%ld",_1070_main());
  return 0;
}
