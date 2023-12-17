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

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

typedef int64_t(*function2)(void);

/* Function forward definitions */
int64_t _64_main(void);
int64_t _70_f(void);

/* Function definitions */
int64_t _64_main(void){
    int64_t _64_t1;
    int64_t _64_t2;
    int64_t _64_t3;
    int64_t _64_t4;
    struct0 _65_x;
    int64_t _64_t6;
    int64_t _64_t7;
    int64_t* _64_t8;
    int64_t _64_t9;
    struct1 _65_y;
    function2 _64_t10;
    int64_t _64_t11;
    int64_t _64_$retval;
    _64_t1 = 0;
    _64_t2 = 0;
    _64_t3 = 0;
    _64_t4 = 0;
    _65_x = (struct0) {_64_t1, _64_t2, _64_t3, _64_t4};
    _64_t6 = 0;
    _64_t7 = 4;
    $bounds_check(_64_t6, _64_t7, "tests/integration/lint/slice-neg-bounds-check.orng:4:16:\n    let y = []x\n              ^");
    _64_t8 = ((int64_t*)&_65_x + _64_t6);
    _64_t9 = 4;
    _65_y = (struct1) {_64_t8, _64_t9};
    _64_t10 = _70_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-neg-bounds-check.orng:5:9:\n    y[f()]\n       ^";
    _64_t11 = _64_t10();
    $line_idx--;
    $bounds_check(_64_t11, _65_y._1, "tests/integration/lint/slice-neg-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _64_$retval = *((int64_t*)_65_y._0 + _64_t11);
    return _64_$retval;
}

int64_t _70_f(void){
    int64_t _70_$retval;
    _70_$retval = -100;
    return _70_$retval;
}

int main(void) {
  printf("%ld",_64_main());
  return 0;
}
