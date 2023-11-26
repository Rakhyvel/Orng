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
int64_t _7_main(void);
int64_t _9_f(void);

/* Function definitions */
int64_t _7_main(void) {
    int64_t _7_t1;
    int64_t _7_t2;
    int64_t _7_t3;
    int64_t _7_t4;
    struct0 _8_x;
    function1 _7_t6;
    int64_t _7_t7;
    int64_t _7_$retval;
    _7_t1 = 0;
    _7_t2 = 0;
    _7_t3 = 0;
    _7_t4 = 0;
    _8_x = (struct0) {_7_t1, _7_t2, _7_t3, _7_t4};
    _7_t6 = _9_f;
    $lines[$line_idx++] = "tests/integration/lint/array-copy-pos-bounds-check.orng:4:9:\n    x[f()] = 0\n       ^";
    _7_t7 = _7_t6();
    $line_idx--;
    *((int64_t*)&_8_x + _7_t7) = 0;
    _7_$retval = 0;
    return _7_$retval;
}

int64_t _9_f(void) {
    int64_t _9_$retval;
    _9_$retval = 100;
    return _9_$retval;
}

int main(void) {
  printf("%ld",_7_main());
  return 0;
}
