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
int64_t _1035_main(void);
int64_t _1037_f(void);

/* Function definitions */
int64_t _1035_main(void){
    int64_t _1035_t1;
    int64_t _1035_t2;
    int64_t _1035_t3;
    int64_t _1035_t4;
    struct0 _1036_x;
    int64_t _1035_t6;
    int64_t _1035_t7;
    int64_t* _1035_t8;
    int64_t _1035_t9;
    struct1 _1036_y;
    function2 _1035_t10;
    int64_t _1035_t11;
    int64_t _1035_$retval;
    _1035_t1 = 0;
    _1035_t2 = 0;
    _1035_t3 = 0;
    _1035_t4 = 0;
    _1036_x = (struct0) {_1035_t1, _1035_t2, _1035_t3, _1035_t4};
    _1035_t6 = 0;
    _1035_t7 = 4;
    $bounds_check(_1035_t6, _1035_t7, "tests/integration/lint/slice-neg-bounds-check.orng:4:16:\n    let y = []x\n              ^");
    _1035_t8 = ((int64_t*)&_1036_x + _1035_t6);
    _1035_t9 = 4;
    _1036_y = (struct1) {_1035_t8, _1035_t9};
    _1035_t10 = _1037_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-neg-bounds-check.orng:5:9:\n    y[f()]\n       ^";
    _1035_t11 = _1035_t10();
    $line_idx--;
    $bounds_check(_1035_t11, _1036_y._1, "tests/integration/lint/slice-neg-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1035_$retval = *((int64_t*)_1036_y._0 + _1035_t11);
    return _1035_$retval;
}

int64_t _1037_f(void){
    int64_t _1037_$retval;
    _1037_$retval = -100;
    return _1037_$retval;
}

int main(void) {
  printf("%ld",_1035_main());
  return 0;
}
