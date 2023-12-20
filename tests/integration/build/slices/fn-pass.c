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
int64_t _1271_main(void);
int64_t _1273_f(struct1 _1273_x);

/* Function definitions */
int64_t _1271_main(void){
    int64_t _1271_t1;
    int64_t _1271_t2;
    int64_t _1271_t3;
    int64_t _1271_t4;
    struct0 _1272_x;
    int64_t _1271_t6;
    int64_t _1271_t7;
    int64_t* _1271_t8;
    int64_t _1271_t9;
    struct1 _1272_y;
    function2 _1271_t10;
    int64_t _1271_t11;
    int64_t _1271_$retval;
    _1271_t1 = 1;
    _1271_t2 = 2;
    _1271_t3 = 3;
    _1271_t4 = 4;
    _1272_x = (struct0) {_1271_t1, _1271_t2, _1271_t3, _1271_t4};
    _1271_t6 = 0;
    _1271_t7 = 4;
    $bounds_check(_1271_t6, _1271_t7, "tests/integration/slices/fn-pass.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1271_t8 = ((int64_t*)&_1272_x + _1271_t6);
    _1271_t9 = 4;
    _1272_y = (struct1) {_1271_t8, _1271_t9};
    _1271_t10 = _1273_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _1271_t11 = _1271_t10(_1272_y);
    $line_idx--;
    _1271_$retval = _1271_t11;
    return _1271_$retval;
}

int64_t _1273_f(struct1 _1273_x){
    int64_t _1273_t0;
    int64_t _1273_t1;
    int64_t _1273_$retval;
    _1273_t0 = 1;
    _1273_t1 = 80;
    $bounds_check(_1273_t0, _1273_x._1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    _1273_$retval = $add_int64_t(*((int64_t*)_1273_x._0 + _1273_t0), _1273_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _1273_$retval;
}

int main(void) {
  printf("%ld",_1271_main());
  return 0;
}
