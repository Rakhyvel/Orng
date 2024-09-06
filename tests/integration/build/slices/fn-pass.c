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
int64_t _1386_main(void);
int64_t _1388_f(struct struct1 _1388_x);


/* Function definitions */
int64_t _1386_main(void){
    int64_t _1386_t1;
    int64_t _1386_t2;
    int64_t _1386_t3;
    int64_t _1386_t4;
    struct struct0 _1387_x;
    int64_t _1386_t7;
    int64_t _1386_t8;
    int64_t* _1386_t9;
    int64_t _1386_t10;
    struct struct1 _1387_y;
    function2 _1386_t12;
    int64_t _1386_t13;
    int64_t _1386_$retval;
    _1386_t1 = 1;
    _1386_t2 = 2;
    _1386_t3 = 3;
    _1386_t4 = 4;
    _1387_x = (struct struct0) {_1386_t1, _1386_t2, _1386_t3, _1386_t4};
    _1386_t7 = 0;
    _1386_t8 = 4;
    $bounds_check(_1386_t7, _1386_t8, "tests/integration/slices/fn-pass.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1386_t9 = ((int64_t*)&_1387_x + _1386_t7);
    _1386_t10 = 4;
    _1387_y = (struct struct1) {_1386_t9, _1386_t10};
    _1386_t12 = (function2) _1388_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _1386_t13 = _1386_t12(_1387_y);
    $line_idx--;
    _1386_$retval = _1386_t13;
    return _1386_$retval;
}

int64_t _1388_f(struct struct1 _1388_x){
    int64_t _1388_t0;
    int64_t _1388_t1;
    int64_t _1388_$retval;
    _1388_t0 = 1;
    _1388_t1 = 80;
    $bounds_check(_1388_t0, _1388_x._1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    _1388_$retval = $add_int64_t(*((int64_t*)_1388_x._0 + _1388_t0), _1388_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _1388_$retval;
}


int main(void) {
  printf("%ld",_1386_main());
  return 0;
}
