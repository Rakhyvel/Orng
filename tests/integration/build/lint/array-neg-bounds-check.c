/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

typedef int64_t(*function1)(void);

/* Function forward definitions */
int64_t _1043_main(void);
int64_t _1045_f(void);

/* Function definitions */
int64_t _1043_main(void){
    int64_t _1043_t1;
    int64_t _1043_t2;
    int64_t _1043_t3;
    int64_t _1043_t4;
    struct struct0 _1044_x;
    function1 _1043_t5;
    int64_t _1043_t6;
    int64_t _1043_t7;
    int64_t _1043_$retval;
    _1043_t1 = 0;
    _1043_t2 = 0;
    _1043_t3 = 0;
    _1043_t4 = 0;
    _1044_x = (struct struct0) {_1043_t1, _1043_t2, _1043_t3, _1043_t4};
    _1043_t5 = _1045_f;
    $lines[$line_idx++] = "tests/integration/lint/array-neg-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _1043_t6 = _1043_t5();
    $line_idx--;
    _1043_t7 = 4;
    $bounds_check(_1043_t6, _1043_t7, "tests/integration/lint/array-neg-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1043_$retval = *((int64_t*)&_1044_x + _1043_t6);
    return _1043_$retval;
}

int64_t _1045_f(void){
    int64_t _1045_$retval;
    _1045_$retval = -100;
    return _1045_$retval;
}

int main(void) {
  printf("%ld",_1043_main());
  return 0;
}
