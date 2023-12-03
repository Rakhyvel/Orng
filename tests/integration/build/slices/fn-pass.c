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

typedef int64_t(*function2)(struct1);

/* Function forward definitions */
int64_t _947_main(void);
int64_t _949_f(struct1 _949_x);

/* Function definitions */
int64_t _947_main(void) {
    int64_t _947_t1;
    int64_t _947_t2;
    int64_t _947_t3;
    int64_t _947_t4;
    struct0 _948_x;
    int64_t _947_t6;
    int64_t* _947_t7;
    int64_t _947_t8;
    struct1 _948_y;
    function2 _947_t9;
    int64_t _947_t10;
    int64_t _947_$retval;
    _947_t1 = 1;
    _947_t2 = 2;
    _947_t3 = 3;
    _947_t4 = 4;
    _948_x = (struct0) {_947_t1, _947_t2, _947_t3, _947_t4};
    _947_t6 = 0;
    _947_t7 = ((int64_t*)&_948_x + _947_t6);
    _947_t8 = 4;
    _948_y = (struct1) {_947_t7, _947_t8};
    _947_t9 = _949_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _947_t10 = _947_t9(_948_y);
    $line_idx--;
    _947_$retval = _947_t10;
    return _947_$retval;
}

int64_t _949_f(struct1 _949_x) {
    int64_t _949_t0;
    int64_t _949_t1;
    int64_t _949_$retval;
    _949_t0 = 1;
    _949_t1 = 80;
    _949_$retval = $add_int64_t(*((int64_t*)_949_x._0 + _949_t0), _949_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _949_$retval;
}

int main(void) {
  printf("%ld",_947_main());
  return 0;
}
