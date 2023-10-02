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

/* Function forward definitions */
int64_t _1_main();
int64_t _3_f();

/* Function definitions */
int64_t _1_main() {
    struct0 _2_x;
    int64_t* _1_t9;
    struct1 _2_y;
    int64_t _1_t11;
    int64_t _1_$retval;
    _2_x = (struct0) {0, 0, 0, 0};
    _1_t9 = (int64_t*)&_2_x;
    _2_y = (struct1) {_1_t9, 4};
$lines[$line_idx++] = "tests/integration/lint/slice-neg-bounds-check.orng:5:9:\n    y[f()]\n       ^";    _1_t11 = _3_f();
    $line_idx--;
    $bounds_check(_1_t11, 4, "tests/integration/lint/slice-neg-bounds-check.orng:5:7:\n    y[f()]\n     ^");
    _1_$retval = *((int64_t*)_2_y._0 + _1_t11);
    return _1_$retval;
}

int64_t _3_f() {
    int64_t _3_$retval;
    _3_$retval = -100;
    return _3_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
