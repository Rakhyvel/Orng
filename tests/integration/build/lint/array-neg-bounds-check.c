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
int64_t _1025_main(void);
int64_t _1027_f(void);

/* Function definitions */
int64_t _1025_main(void){
    int64_t _1025_t1;
    int64_t _1025_t2;
    int64_t _1025_t3;
    int64_t _1025_t4;
    struct struct0 _1026_x;
    function1 _1025_t5;
    int64_t _1025_t6;
    int64_t _1025_t7;
    int64_t _1025_$retval;
    _1025_t1 = 0;
    _1025_t2 = 0;
    _1025_t3 = 0;
    _1025_t4 = 0;
    _1026_x = (struct struct0) {_1025_t1, _1025_t2, _1025_t3, _1025_t4};
    _1025_t5 = _1027_f;
    $lines[$line_idx++] = "tests/integration/lint/array-neg-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _1025_t6 = _1025_t5();
    $line_idx--;
    _1025_t7 = 4;
    $bounds_check(_1025_t6, _1025_t7, "tests/integration/lint/array-neg-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1025_$retval = *((int64_t*)&_1026_x + _1025_t6);
    return _1025_$retval;
}

int64_t _1027_f(void){
    int64_t _1027_$retval;
    _1027_$retval = -100;
    return _1027_$retval;
}

int main(void) {
  printf("%ld",_1025_main());
  return 0;
}
