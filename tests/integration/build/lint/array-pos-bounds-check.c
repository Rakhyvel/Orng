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

/* Function forward definitions */
int64_t _1_main();
int64_t _3_f();

/* Function definitions */
int64_t _1_main() {
    struct0 _2_x;
    int64_t _1_t5;
    int64_t _1_$retval;
    _2_x = (struct0) {0, 0, 0, 0};
    $lines[$line_idx++] = "tests/integration/lint/array-pos-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _1_t5 = _3_f();
    $line_idx--;
    $bounds_check(_1_t5, 4, "tests/integration/lint/array-pos-bounds-check.orng:4:7:\n    x[f()]\n     ^");
    _1_$retval = *((int64_t*)&_2_x + _1_t5);
    return _1_$retval;
}

int64_t _3_f() {
    int64_t _3_$retval;
    _3_$retval = 100;
    return _3_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
