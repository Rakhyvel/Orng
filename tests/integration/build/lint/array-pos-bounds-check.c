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
int64_t _1030_main(void);
int64_t _1032_f(void);

/* Function definitions */
int64_t _1030_main(void){
    int64_t _1030_t1;
    int64_t _1030_t2;
    int64_t _1030_t3;
    int64_t _1030_t4;
    struct0 _1031_x;
    function1 _1030_t5;
    int64_t _1030_t6;
    int64_t _1030_t7;
    int64_t _1030_$retval;
    _1030_t1 = 0;
    _1030_t2 = 0;
    _1030_t3 = 0;
    _1030_t4 = 0;
    _1031_x = (struct0) {_1030_t1, _1030_t2, _1030_t3, _1030_t4};
    _1030_t5 = _1032_f;
    $lines[$line_idx++] = "tests/integration/lint/array-pos-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _1030_t6 = _1030_t5();
    $line_idx--;
    _1030_t7 = 4;
    $bounds_check(_1030_t6, _1030_t7, "tests/integration/lint/array-pos-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1030_$retval = *((int64_t*)&_1031_x + _1030_t6);
    return _1030_$retval;
}

int64_t _1032_f(void){
    int64_t _1032_$retval;
    _1032_$retval = 100;
    return _1032_$retval;
}

int main(void) {
  printf("%ld",_1030_main());
  return 0;
}
