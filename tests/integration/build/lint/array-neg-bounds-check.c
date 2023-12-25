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
int64_t _1012_main(void);
int64_t _1014_f(void);

/* Function definitions */
int64_t _1012_main(void){
    int64_t _1012_t1;
    int64_t _1012_t2;
    int64_t _1012_t3;
    int64_t _1012_t4;
    struct0 _1013_x;
    function1 _1012_t5;
    int64_t _1012_t6;
    int64_t _1012_t7;
    int64_t _1012_$retval;
    _1012_t1 = 0;
    _1012_t2 = 0;
    _1012_t3 = 0;
    _1012_t4 = 0;
    _1013_x = (struct0) {_1012_t1, _1012_t2, _1012_t3, _1012_t4};
    _1012_t5 = _1014_f;
    $lines[$line_idx++] = "tests/integration/lint/array-neg-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _1012_t6 = _1012_t5();
    $line_idx--;
    _1012_t7 = 4;
    $bounds_check(_1012_t6, _1012_t7, "tests/integration/lint/array-neg-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1012_$retval = *((int64_t*)&_1013_x + _1012_t6);
    return _1012_$retval;
}

int64_t _1014_f(void){
    int64_t _1014_$retval;
    _1014_$retval = -100;
    return _1014_$retval;
}

int main(void) {
  printf("%ld",_1012_main());
  return 0;
}
