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
int64_t _1489_main(void);
int64_t _1491_f(struct1 _1491_x);

/* Function definitions */
int64_t _1489_main(void){
    int64_t _1489_t1;
    int64_t _1489_t2;
    int64_t _1489_t3;
    int64_t _1489_t4;
    struct0 _1490_x;
    int64_t _1489_t6;
    int64_t _1489_t7;
    int64_t* _1489_t8;
    int64_t _1489_t9;
    struct1 _1490_y;
    function2 _1489_t10;
    int64_t _1489_t11;
    int64_t _1489_$retval;
    _1489_t1 = 1;
    _1489_t2 = 2;
    _1489_t3 = 3;
    _1489_t4 = 4;
    _1490_x = (struct0) {_1489_t1, _1489_t2, _1489_t3, _1489_t4};
    _1489_t6 = 0;
    _1489_t7 = 4;
    $bounds_check(_1489_t6, _1489_t7, "tests/integration/slices/fn-pass.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1489_t8 = ((int64_t*)&_1490_x + _1489_t6);
    _1489_t9 = 4;
    _1490_y = (struct1) {_1489_t8, _1489_t9};
    _1489_t10 = _1491_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _1489_t11 = _1489_t10(_1490_y);
    $line_idx--;
    _1489_$retval = _1489_t11;
    return _1489_$retval;
}

int64_t _1491_f(struct1 _1491_x){
    int64_t _1491_t0;
    int64_t _1491_t1;
    int64_t _1491_$retval;
    _1491_t0 = 1;
    _1491_t1 = 80;
    $bounds_check(_1491_t0, _1491_x._1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    _1491_$retval = $add_int64_t(*((int64_t*)_1491_x._0 + _1491_t0), _1491_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _1491_$retval;
}

int main(void) {
  printf("%ld",_1489_main());
  return 0;
}
