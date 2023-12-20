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
int64_t _1002_main(void);
int64_t _1004_f(void);

/* Function definitions */
int64_t _1002_main(void){
    int64_t _1002_t1;
    int64_t _1002_t2;
    int64_t _1002_t3;
    int64_t _1002_t4;
    struct0 _1003_x;
    function1 _1002_t6;
    int64_t _1002_t7;
    int64_t _1002_t8;
    int64_t _1002_$retval;
    _1002_t1 = 0;
    _1002_t2 = 0;
    _1002_t3 = 0;
    _1002_t4 = 0;
    _1003_x = (struct0) {_1002_t1, _1002_t2, _1002_t3, _1002_t4};
    _1002_t6 = _1004_f;
    $lines[$line_idx++] = "tests/integration/lint/array-copy-neg-bounds-check.orng:4:9:\n    x[f()] = 0\n       ^";
    _1002_t7 = _1002_t6();
    $line_idx--;
    _1002_t8 = 4;
    $bounds_check(_1002_t7, _1002_t8, "tests/integration/lint/array-copy-neg-bounds-check.orng:4:15:\n    x[f()] = 0\n             ^");
    *((int64_t*)&_1003_x + _1002_t7) = 0;
    _1002_$retval = 0;
    return _1002_$retval;
}

int64_t _1004_f(void){
    int64_t _1004_$retval;
    _1004_$retval = -100;
    return _1004_$retval;
}

int main(void) {
  printf("%ld",_1002_main());
  return 0;
}
