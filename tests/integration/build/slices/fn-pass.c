/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
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
int64_t _1435_main(void);
int64_t _1437_f(struct struct1 _1437_x);


/* Function definitions */
int64_t _1435_main(void){
    int64_t _1435_t1;
    int64_t _1435_t2;
    int64_t _1435_t3;
    int64_t _1435_t4;
    struct struct0 _1436_x;
    int64_t _1435_t7;
    int64_t _1435_t8;
    int64_t* _1435_t9;
    int64_t _1435_t10;
    struct struct1 _1436_y;
    function2 _1435_t12;
    int64_t _1435_t13;
    int64_t _1435_$retval;
    _1435_t1 = 1;
    _1435_t2 = 2;
    _1435_t3 = 3;
    _1435_t4 = 4;
    _1436_x = (struct struct0) {_1435_t1, _1435_t2, _1435_t3, _1435_t4};
    _1435_t7 = 0;
    _1435_t8 = 4;
    $bounds_check(_1435_t7, _1435_t8, "tests/integration/slices/fn-pass.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1435_t9 = ((int64_t*)&_1436_x + _1435_t7);
    _1435_t10 = 4;
    _1436_y = (struct struct1) {_1435_t9, _1435_t10};
    _1435_t12 = (function2) _1437_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _1435_t13 = _1435_t12(_1436_y);
    $line_idx--;
    _1435_$retval = _1435_t13;
    return _1435_$retval;
}

int64_t _1437_f(struct struct1 _1437_x){
    int64_t _1437_t0;
    int64_t _1437_t1;
    int64_t _1437_$retval;
    _1437_t0 = 1;
    _1437_t1 = 80;
    $bounds_check(_1437_t0, _1437_x._1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    _1437_$retval = $add_int64_t(*((int64_t*)_1437_x._0 + _1437_t0), _1437_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _1437_$retval;
}


int main(void) {
  printf("%ld",_1435_main());
  return 0;
}
