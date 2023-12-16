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
int64_t _1238_main(void);
int64_t _1240_f(struct1 _1240_x);

/* Function definitions */
int64_t _1238_main(void){
    int64_t _1238_t1;
    int64_t _1238_t2;
    int64_t _1238_t3;
    int64_t _1238_t4;
    struct0 _1239_x;
    int64_t _1238_t6;
    int64_t* _1238_t7;
    int64_t _1238_t8;
    struct1 _1239_y;
    function2 _1238_t9;
    int64_t _1238_t10;
    int64_t _1238_$retval;
    _1238_t1 = 1;
    _1238_t2 = 2;
    _1238_t3 = 3;
    _1238_t4 = 4;
    _1239_x = (struct0) {_1238_t1, _1238_t2, _1238_t3, _1238_t4};
    _1238_t6 = 0;
    _1238_t7 = ((int64_t*)&_1239_x + _1238_t6);
    _1238_t8 = 4;
    _1239_y = (struct1) {_1238_t7, _1238_t8};
    _1238_t9 = _1240_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _1238_t10 = _1238_t9(_1239_y);
    $line_idx--;
    _1238_$retval = _1238_t10;
    return _1238_$retval;
}

int64_t _1240_f(struct1 _1240_x){
    int64_t _1240_t0;
    int64_t _1240_t1;
    int64_t _1240_$retval;
    _1240_t0 = 1;
    _1240_t1 = 80;
    _1240_$retval = $add_int64_t(*((int64_t*)_1240_x._0 + _1240_t0), _1240_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _1240_$retval;
}

int main(void) {
  printf("%ld",_1238_main());
  return 0;
}
