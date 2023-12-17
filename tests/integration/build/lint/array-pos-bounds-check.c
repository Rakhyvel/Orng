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
int64_t _29_main(void);
int64_t _35_f(void);

/* Function definitions */
int64_t _29_main(void){
    int64_t _29_t1;
    int64_t _29_t2;
    int64_t _29_t3;
    int64_t _29_t4;
    struct0 _30_x;
    function1 _29_t5;
    int64_t _29_t6;
    int64_t _29_t7;
    int64_t _29_$retval;
    _29_t1 = 0;
    _29_t2 = 0;
    _29_t3 = 0;
    _29_t4 = 0;
    _30_x = (struct0) {_29_t1, _29_t2, _29_t3, _29_t4};
    _29_t5 = _35_f;
    $lines[$line_idx++] = "tests/integration/lint/array-pos-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _29_t6 = _29_t5();
    $line_idx--;
    _29_t7 = 4;
    $bounds_check(_29_t6, _29_t7, "tests/integration/lint/array-pos-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _29_$retval = *((int64_t*)&_30_x + _29_t6);
    return _29_$retval;
}

int64_t _35_f(void){
    int64_t _35_$retval;
    _35_$retval = 100;
    return _35_$retval;
}

int main(void) {
  printf("%ld",_29_main());
  return 0;
}
