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
int64_t _1_main(void);
int64_t _3_f(struct1 _3_x);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _2_x;
    int64_t* _1_t9;
    struct1 _2_y;
    int64_t _1_t11;
    int64_t _1_$retval;
    _2_x = (struct0) {1, 2, 3, 4};
    _1_t9 = (int64_t*)&_2_x;
    _2_y = (struct1) {_1_t9, 4};
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _1_t11 = _3_f(_2_y);
    $line_idx--;
    _1_$retval = _1_t11;
    return _1_$retval;
}

int64_t _3_f(struct1 _3_x) {
    int64_t _3_$retval;
    $bounds_check(1, _3_x._1, "tests/integration/slices/fn-pass.orng:8:24:\nfn f(x: []Int)->Int {x[1] + 80}\n                      ^");
    _3_$retval = $add_int64_t(*((int64_t*)_3_x._0 + 1), 80, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _3_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
