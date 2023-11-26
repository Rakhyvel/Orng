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
int64_t _17_main(void);
int64_t _19_f(void);

/* Function definitions */
int64_t _17_main(void) {
    int64_t _17_t1;
    int64_t _17_t2;
    int64_t _17_t3;
    int64_t _17_t4;
    struct0 _18_x;
    function1 _17_t5;
    int64_t _17_t6;
    int64_t _17_$retval;
    _17_t1 = 0;
    _17_t2 = 0;
    _17_t3 = 0;
    _17_t4 = 0;
    _18_x = (struct0) {_17_t1, _17_t2, _17_t3, _17_t4};
    _17_t5 = _19_f;
    $lines[$line_idx++] = "tests/integration/lint/array-pos-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _17_t6 = _17_t5();
    $line_idx--;
    _17_$retval = *((int64_t*)&_18_x + _17_t6);
    return _17_$retval;
}

int64_t _19_f(void) {
    int64_t _19_$retval;
    _19_$retval = 100;
    return _19_$retval;
}

int main(void) {
  printf("%ld",_17_main());
  return 0;
}
