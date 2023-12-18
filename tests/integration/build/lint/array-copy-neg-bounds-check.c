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
int64_t _1134_main(void);
int64_t _1140_f(void);

/* Function definitions */
int64_t _1134_main(void){
    int64_t _1134_t1;
    int64_t _1134_t2;
    int64_t _1134_t3;
    int64_t _1134_t4;
    struct0 _1135_x;
    function1 _1134_t6;
    int64_t _1134_t7;
    int64_t _1134_t8;
    int64_t _1134_$retval;
    _1134_t1 = 0;
    _1134_t2 = 0;
    _1134_t3 = 0;
    _1134_t4 = 0;
    _1135_x = (struct0) {_1134_t1, _1134_t2, _1134_t3, _1134_t4};
    _1134_t6 = _1140_f;
    $lines[$line_idx++] = "tests/integration/lint/array-copy-neg-bounds-check.orng:4:9:\n    x[f()] = 0\n       ^";
    _1134_t7 = _1134_t6();
    $line_idx--;
    _1134_t8 = 4;
    $bounds_check(_1134_t7, _1134_t8, "tests/integration/lint/array-copy-neg-bounds-check.orng:4:15:\n    x[f()] = 0\n             ^");
    *((int64_t*)&_1135_x + _1134_t7) = 0;
    _1134_$retval = 0;
    return _1134_$retval;
}

int64_t _1140_f(void){
    int64_t _1140_$retval;
    _1140_$retval = -100;
    return _1140_$retval;
}

int main(void) {
  printf("%ld",_1134_main());
  return 0;
}
