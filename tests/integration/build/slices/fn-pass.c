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
int64_t _1298_main(void);
int64_t _1300_f(struct struct1 _1300_x);

/* Function definitions */
int64_t _1298_main(void){
    int64_t _1298_t1;
    int64_t _1298_t2;
    int64_t _1298_t3;
    int64_t _1298_t4;
    struct struct0 _1299_x;
    int64_t _1298_t6;
    int64_t _1298_t7;
    int64_t* _1298_t8;
    int64_t _1298_t9;
    struct struct1 _1299_y;
    function2 _1298_t10;
    int64_t _1298_t11;
    int64_t _1298_$retval;
    _1298_t1 = 1;
    _1298_t2 = 2;
    _1298_t3 = 3;
    _1298_t4 = 4;
    _1299_x = (struct struct0) {_1298_t1, _1298_t2, _1298_t3, _1298_t4};
    _1298_t6 = 0;
    _1298_t7 = 4;
    $bounds_check(_1298_t6, _1298_t7, "tests/integration/slices/fn-pass.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1298_t8 = ((int64_t*)&_1299_x + _1298_t6);
    _1298_t9 = 4;
    _1299_y = (struct struct1) {_1298_t8, _1298_t9};
    _1298_t10 = _1300_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _1298_t11 = _1298_t10(_1299_y);
    $line_idx--;
    _1298_$retval = _1298_t11;
    return _1298_$retval;
}

int64_t _1300_f(struct struct1 _1300_x){
    int64_t _1300_t0;
    int64_t _1300_t1;
    int64_t _1300_$retval;
    _1300_t0 = 1;
    _1300_t1 = 80;
    $bounds_check(_1300_t0, _1300_x._1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    _1300_$retval = $add_int64_t(*((int64_t*)_1300_x._0 + _1300_t0), _1300_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _1300_$retval;
}

int main(void) {
  printf("%ld",_1298_main());
  return 0;
}
