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
int64_t _1345_main(void);
int64_t _1347_f(struct struct1 _1347_x);


/* Function definitions */
int64_t _1345_main(void){
    int64_t _1345_t1;
    int64_t _1345_t2;
    int64_t _1345_t3;
    int64_t _1345_t4;
    struct struct0 _1346_x;
    int64_t _1345_t6;
    int64_t _1345_t7;
    int64_t* _1345_t8;
    int64_t _1345_t9;
    struct struct1 _1346_y;
    function2 _1345_t10;
    int64_t _1345_t11;
    int64_t _1345_$retval;
    _1345_t1 = 1;
    _1345_t2 = 2;
    _1345_t3 = 3;
    _1345_t4 = 4;
    _1346_x = (struct struct0) {_1345_t1, _1345_t2, _1345_t3, _1345_t4};
    _1345_t6 = 0;
    _1345_t7 = 4;
    $bounds_check(_1345_t6, _1345_t7, "tests/integration/slices/fn-pass.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1345_t8 = ((int64_t*)&_1346_x + _1345_t6);
    _1345_t9 = 4;
    _1346_y = (struct struct1) {_1345_t8, _1345_t9};
    _1345_t10 = _1347_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _1345_t11 = _1345_t10(_1346_y);
    $line_idx--;
    _1345_$retval = _1345_t11;
    return _1345_$retval;
}

int64_t _1347_f(struct struct1 _1347_x){
    int64_t _1347_t0;
    int64_t _1347_t1;
    int64_t _1347_$retval;
    _1347_t0 = 1;
    _1347_t1 = 80;
    $bounds_check(_1347_t0, _1347_x._1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    _1347_$retval = $add_int64_t(*((int64_t*)_1347_x._0 + _1347_t0), _1347_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _1347_$retval;
}


int main(void) {
  printf("%ld",_1345_main());
  return 0;
}
