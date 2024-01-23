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
int64_t _1318_main(void);
int64_t _1320_f(struct struct1 _1320_x);


/* Function definitions */
int64_t _1318_main(void){
    int64_t _1318_t1;
    int64_t _1318_t2;
    int64_t _1318_t3;
    int64_t _1318_t4;
    struct struct0 _1319_x;
    int64_t _1318_t6;
    int64_t _1318_t7;
    int64_t* _1318_t8;
    int64_t _1318_t9;
    struct struct1 _1319_y;
    function2 _1318_t10;
    int64_t _1318_t11;
    int64_t _1318_$retval;
    _1318_t1 = 1;
    _1318_t2 = 2;
    _1318_t3 = 3;
    _1318_t4 = 4;
    _1319_x = (struct struct0) {_1318_t1, _1318_t2, _1318_t3, _1318_t4};
    _1318_t6 = 0;
    _1318_t7 = 4;
    $bounds_check(_1318_t6, _1318_t7, "tests/integration/slices/fn-pass.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1318_t8 = ((int64_t*)&_1319_x + _1318_t6);
    _1318_t9 = 4;
    _1319_y = (struct struct1) {_1318_t8, _1318_t9};
    _1318_t10 = _1320_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _1318_t11 = _1318_t10(_1319_y);
    $line_idx--;
    _1318_$retval = _1318_t11;
    return _1318_$retval;
}

int64_t _1320_f(struct struct1 _1320_x){
    int64_t _1320_t0;
    int64_t _1320_t1;
    int64_t _1320_$retval;
    _1320_t0 = 1;
    _1320_t1 = 80;
    $bounds_check(_1320_t0, _1320_x._1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    _1320_$retval = $add_int64_t(*((int64_t*)_1320_x._0 + _1320_t0), _1320_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _1320_$retval;
}


int main(void) {
  printf("%ld",_1318_main());
  return 0;
}
