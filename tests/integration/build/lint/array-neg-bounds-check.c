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
int64_t _12_main(void);
int64_t _14_f(void);

/* Function definitions */
int64_t _12_main(void) {
    int64_t _12_t1;
    int64_t _12_t2;
    int64_t _12_t3;
    int64_t _12_t4;
    struct0 _13_x;
    function1 _12_t5;
    int64_t _12_t6;
    int64_t _12_$retval;
    _12_t1 = 0;
    _12_t2 = 0;
    _12_t3 = 0;
    _12_t4 = 0;
    _13_x = (struct0) {_12_t1, _12_t2, _12_t3, _12_t4};
    _12_t5 = _14_f;
    $lines[$line_idx++] = "tests/integration/lint/array-neg-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _12_t6 = _12_t5();
    $line_idx--;
    _12_$retval = *((int64_t*)&_13_x + _12_t6);
    return _12_$retval;
}

int64_t _14_f(void) {
    int64_t _14_$retval;
    _14_$retval = -100;
    return _14_$retval;
}

int main(void) {
  printf("%ld",_12_main());
  return 0;
}
