/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
} struct0;

typedef int64_t(*function1)(void);

/* Function forward definitions */
int64_t _1152_main(void);
int64_t _1158_f(void);

/* Function definitions */
int64_t _1152_main(void){
    int64_t _1152_t1;
    int64_t _1152_t2;
    int64_t _1152_t3;
    int64_t _1152_t4;
    struct0 _1153_x;
    function1 _1152_t5;
    int64_t _1152_t6;
    int64_t _1152_t7;
    int64_t _1152_$retval;
    _1152_t1 = 0;
    _1152_t2 = 0;
    _1152_t3 = 0;
    _1152_t4 = 0;
    _1153_x = (struct0) {_1152_t1, _1152_t2, _1152_t3, _1152_t4};
    _1152_t5 = _1158_f;
    $lines[$line_idx++] = "tests/integration/lint/array-neg-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _1152_t6 = _1152_t5();
    $line_idx--;
    _1152_t7 = 4;
    $bounds_check(_1152_t6, _1152_t7, "tests/integration/lint/array-neg-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1152_$retval = *((int64_t*)&_1153_x + _1152_t6);
    return _1152_$retval;
}

int64_t _1158_f(void){
    int64_t _1158_$retval;
    _1158_$retval = -100;
    return _1158_$retval;
}

int main(void) {
  printf("%ld",_1152_main());
  return 0;
}
