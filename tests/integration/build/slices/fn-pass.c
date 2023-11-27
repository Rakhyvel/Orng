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
int64_t _912_main(void);
int64_t _914_f(struct1 _914_x);

/* Function definitions */
int64_t _912_main(void) {
    int64_t _912_t1;
    int64_t _912_t2;
    int64_t _912_t3;
    int64_t _912_t4;
    struct0 _913_x;
    int64_t _912_t6;
    int64_t* _912_t7;
    int64_t _912_t8;
    struct1 _913_y;
    function2 _912_t9;
    int64_t _912_t10;
    int64_t _912_$retval;
    _912_t1 = 1;
    _912_t2 = 2;
    _912_t3 = 3;
    _912_t4 = 4;
    _913_x = (struct0) {_912_t1, _912_t2, _912_t3, _912_t4};
    _912_t6 = 0;
    _912_t7 = ((int64_t*)&_913_x + _912_t6);
    _912_t8 = 4;
    _913_y = (struct1) {_912_t7, _912_t8};
    _912_t9 = _914_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _912_t10 = _912_t9(_913_y);
    $line_idx--;
    _912_$retval = _912_t10;
    return _912_$retval;
}

int64_t _914_f(struct1 _914_x) {
    int64_t _914_t0;
    int64_t _914_t1;
    int64_t _914_$retval;
    _914_t0 = 1;
    _914_t1 = 80;
    _914_$retval = $add_int64_t(*((int64_t*)_914_x._0 + _914_t0), _914_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _914_$retval;
}

int main(void) {
  printf("%ld",_912_main());
  return 0;
}
