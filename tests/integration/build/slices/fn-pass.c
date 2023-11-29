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
int64_t _1230_main(void);
int64_t _1232_f(struct1 _1232_x);

/* Function definitions */
int64_t _1230_main(void) {
    int64_t _1230_t1;
    int64_t _1230_t2;
    int64_t _1230_t3;
    int64_t _1230_t4;
    struct0 _1231_x;
    int64_t _1230_t6;
    int64_t* _1230_t7;
    int64_t _1230_t8;
    struct1 _1231_y;
    function2 _1230_t9;
    int64_t _1230_t10;
    int64_t _1230_$retval;
    _1230_t1 = 1;
    _1230_t2 = 2;
    _1230_t3 = 3;
    _1230_t4 = 4;
    _1231_x = (struct0) {_1230_t1, _1230_t2, _1230_t3, _1230_t4};
    _1230_t6 = 0;
    _1230_t7 = ((int64_t*)&_1231_x + _1230_t6);
    _1230_t8 = 4;
    _1231_y = (struct1) {_1230_t7, _1230_t8};
    _1230_t9 = _1232_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _1230_t10 = _1230_t9(_1231_y);
    $line_idx--;
    _1230_$retval = _1230_t10;
    return _1230_$retval;
}

int64_t _1232_f(struct1 _1232_x) {
    int64_t _1232_t0;
    int64_t _1232_t1;
    int64_t _1232_$retval;
    _1232_t0 = 1;
    _1232_t1 = 80;
    _1232_$retval = $add_int64_t(*((int64_t*)_1232_x._0 + _1232_t0), _1232_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _1232_$retval;
}

int main(void) {
  printf("%ld",_1230_main());
  return 0;
}
