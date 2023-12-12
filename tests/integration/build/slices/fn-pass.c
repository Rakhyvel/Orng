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
int64_t _998_main(void);
int64_t _1000_f(struct1 _1000_x);

/* Function definitions */
int64_t _998_main(void) {
    int64_t _998_t1;
    int64_t _998_t2;
    int64_t _998_t3;
    int64_t _998_t4;
    struct0 _999_x;
    int64_t _998_t6;
    int64_t* _998_t7;
    int64_t _998_t8;
    struct1 _999_y;
    function2 _998_t9;
    int64_t _998_t10;
    int64_t _998_$retval;
    _998_t1 = 1;
    _998_t2 = 2;
    _998_t3 = 3;
    _998_t4 = 4;
    _999_x = (struct0) {_998_t1, _998_t2, _998_t3, _998_t4};
    _998_t6 = 0;
    _998_t7 = ((int64_t*)&_999_x + _998_t6);
    _998_t8 = 4;
    _999_y = (struct1) {_998_t7, _998_t8};
    _998_t9 = _1000_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _998_t10 = _998_t9(_999_y);
    $line_idx--;
    _998_$retval = _998_t10;
    return _998_$retval;
}

int64_t _1000_f(struct1 _1000_x) {
    int64_t _1000_t0;
    int64_t _1000_t1;
    int64_t _1000_$retval;
    _1000_t0 = 1;
    _1000_t1 = 80;
    _1000_$retval = $add_int64_t(*((int64_t*)_1000_x._0 + _1000_t0), _1000_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _1000_$retval;
}

int main(void) {
  printf("%ld",_998_main());
  return 0;
}
