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
int64_t _1004_main(void);
int64_t _1006_f(struct1 _1006_x);

/* Function definitions */
int64_t _1004_main(void) {
    int64_t _1004_t1;
    int64_t _1004_t2;
    int64_t _1004_t3;
    int64_t _1004_t4;
    struct0 _1005_x;
    int64_t _1004_t6;
    int64_t* _1004_t7;
    int64_t _1004_t8;
    struct1 _1005_y;
    function2 _1004_t9;
    int64_t _1004_t10;
    int64_t _1004_$retval;
    _1004_t1 = 1;
    _1004_t2 = 2;
    _1004_t3 = 3;
    _1004_t4 = 4;
    _1005_x = (struct0) {_1004_t1, _1004_t2, _1004_t3, _1004_t4};
    _1004_t6 = 0;
    _1004_t7 = ((int64_t*)&_1005_x + _1004_t6);
    _1004_t8 = 4;
    _1005_y = (struct1) {_1004_t7, _1004_t8};
    _1004_t9 = _1006_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _1004_t10 = _1004_t9(_1005_y);
    $line_idx--;
    _1004_$retval = _1004_t10;
    return _1004_$retval;
}

int64_t _1006_f(struct1 _1006_x) {
    int64_t _1006_t0;
    int64_t _1006_t1;
    int64_t _1006_$retval;
    _1006_t0 = 1;
    _1006_t1 = 80;
    _1006_$retval = $add_int64_t(*((int64_t*)_1006_x._0 + _1006_t0), _1006_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _1006_$retval;
}

int main(void) {
  printf("%ld",_1004_main());
  return 0;
}
