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
int64_t _1249_main(void);
int64_t _1251_f(struct1 _1251_x);

/* Function definitions */
int64_t _1249_main(void){
    int64_t _1249_t1;
    int64_t _1249_t2;
    int64_t _1249_t3;
    int64_t _1249_t4;
    struct0 _1250_x;
    int64_t _1249_t6;
    int64_t* _1249_t7;
    int64_t _1249_t8;
    struct1 _1250_y;
    function2 _1249_t9;
    int64_t _1249_t10;
    int64_t _1249_$retval;
    _1249_t1 = 1;
    _1249_t2 = 2;
    _1249_t3 = 3;
    _1249_t4 = 4;
    _1250_x = (struct0) {_1249_t1, _1249_t2, _1249_t3, _1249_t4};
    _1249_t6 = 0;
    _1249_t7 = ((int64_t*)&_1250_x + _1249_t6);
    _1249_t8 = 4;
    _1250_y = (struct1) {_1249_t7, _1249_t8};
    _1249_t9 = _1251_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _1249_t10 = _1249_t9(_1250_y);
    $line_idx--;
    _1249_$retval = _1249_t10;
    return _1249_$retval;
}

int64_t _1251_f(struct1 _1251_x){
    int64_t _1251_t0;
    int64_t _1251_t1;
    int64_t _1251_$retval;
    _1251_t0 = 1;
    _1251_t1 = 80;
    _1251_$retval = $add_int64_t(*((int64_t*)_1251_x._0 + _1251_t0), _1251_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _1251_$retval;
}

int main(void) {
  printf("%ld",_1249_main());
  return 0;
}
