/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function2)(struct struct1);

/* Function forward definitions */
int64_t _1303_main(void);
int64_t _1305_f(struct struct1 _1305_x);

/* Function definitions */
int64_t _1303_main(void){
    int64_t _1303_t1;
    int64_t _1303_t2;
    int64_t _1303_t3;
    int64_t _1303_t4;
    struct struct0 _1304_x;
    int64_t _1303_t6;
    int64_t _1303_t7;
    int64_t* _1303_t8;
    int64_t _1303_t9;
    struct struct1 _1304_y;
    function2 _1303_t10;
    int64_t _1303_t11;
    int64_t _1303_$retval;
    _1303_t1 = 1;
    _1303_t2 = 2;
    _1303_t3 = 3;
    _1303_t4 = 4;
    _1304_x = (struct struct0) {_1303_t1, _1303_t2, _1303_t3, _1303_t4};
    _1303_t6 = 0;
    _1303_t7 = 4;
    $bounds_check(_1303_t6, _1303_t7, "tests/integration/slices/fn-pass.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1303_t8 = ((int64_t*)&_1304_x + _1303_t6);
    _1303_t9 = 4;
    _1304_y = (struct struct1) {_1303_t8, _1303_t9};
    _1303_t10 = _1305_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _1303_t11 = _1303_t10(_1304_y);
    $line_idx--;
    _1303_$retval = _1303_t11;
    return _1303_$retval;
}

int64_t _1305_f(struct struct1 _1305_x){
    int64_t _1305_t0;
    int64_t _1305_t1;
    int64_t _1305_$retval;
    _1305_t0 = 1;
    _1305_t1 = 80;
    $bounds_check(_1305_t0, _1305_x._1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    _1305_$retval = $add_int64_t(*((int64_t*)_1305_x._0 + _1305_t0), _1305_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _1305_$retval;
}

int main(void) {
  printf("%ld",_1303_main());
  return 0;
}
