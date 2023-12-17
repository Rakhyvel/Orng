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
int64_t _11_main(void);
int64_t _17_f(void);

/* Function definitions */
int64_t _11_main(void){
    int64_t _11_t1;
    int64_t _11_t2;
    int64_t _11_t3;
    int64_t _11_t4;
    struct0 _12_x;
    function1 _11_t6;
    int64_t _11_t7;
    int64_t _11_t8;
    int64_t _11_$retval;
    _11_t1 = 0;
    _11_t2 = 0;
    _11_t3 = 0;
    _11_t4 = 0;
    _12_x = (struct0) {_11_t1, _11_t2, _11_t3, _11_t4};
    _11_t6 = _17_f;
    $lines[$line_idx++] = "tests/integration/lint/array-copy-pos-bounds-check.orng:4:9:\n    x[f()] = 0\n       ^";
    _11_t7 = _11_t6();
    $line_idx--;
    _11_t8 = 4;
    $bounds_check(_11_t7, _11_t8, "tests/integration/lint/array-copy-pos-bounds-check.orng:4:15:\n    x[f()] = 0\n             ^");
    *((int64_t*)&_12_x + _11_t7) = 0;
    _11_$retval = 0;
    return _11_$retval;
}

int64_t _17_f(void){
    int64_t _17_$retval;
    _17_$retval = 100;
    return _17_$retval;
}

int main(void) {
  printf("%ld",_11_main());
  return 0;
}
