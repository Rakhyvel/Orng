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
int64_t _1313_main(void);
int64_t _1315_f(struct struct1 _1315_x);

/* Function definitions */
int64_t _1313_main(void){
    int64_t _1313_t1;
    int64_t _1313_t2;
    int64_t _1313_t3;
    int64_t _1313_t4;
    struct struct0 _1314_x;
    int64_t _1313_t6;
    int64_t _1313_t7;
    int64_t* _1313_t8;
    int64_t _1313_t9;
    struct struct1 _1314_y;
    function2 _1313_t10;
    int64_t _1313_t11;
    int64_t _1313_$retval;
    _1313_t1 = 1;
    _1313_t2 = 2;
    _1313_t3 = 3;
    _1313_t4 = 4;
    _1314_x = (struct struct0) {_1313_t1, _1313_t2, _1313_t3, _1313_t4};
    _1313_t6 = 0;
    _1313_t7 = 4;
    $bounds_check(_1313_t6, _1313_t7, "tests/integration/slices/fn-pass.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1313_t8 = ((int64_t*)&_1314_x + _1313_t6);
    _1313_t9 = 4;
    _1314_y = (struct struct1) {_1313_t8, _1313_t9};
    _1313_t10 = _1315_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _1313_t11 = _1313_t10(_1314_y);
    $line_idx--;
    _1313_$retval = _1313_t11;
    return _1313_$retval;
}

int64_t _1315_f(struct struct1 _1315_x){
    int64_t _1315_t0;
    int64_t _1315_t1;
    int64_t _1315_$retval;
    _1315_t0 = 1;
    _1315_t1 = 80;
    $bounds_check(_1315_t0, _1315_x._1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    _1315_$retval = $add_int64_t(*((int64_t*)_1315_x._0 + _1315_t0), _1315_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _1315_$retval;
}

int main(void) {
  printf("%ld",_1313_main());
  return 0;
}
