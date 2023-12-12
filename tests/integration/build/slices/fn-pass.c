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
int64_t _979_main(void);
int64_t _981_f(struct1 _981_x);

/* Function definitions */
int64_t _979_main(void) {
    int64_t _979_t1;
    int64_t _979_t2;
    int64_t _979_t3;
    int64_t _979_t4;
    struct0 _980_x;
    int64_t _979_t6;
    int64_t* _979_t7;
    int64_t _979_t8;
    struct1 _980_y;
    function2 _979_t9;
    int64_t _979_t10;
    int64_t _979_$retval;
    _979_t1 = 1;
    _979_t2 = 2;
    _979_t3 = 3;
    _979_t4 = 4;
    _980_x = (struct0) {_979_t1, _979_t2, _979_t3, _979_t4};
    _979_t6 = 0;
    _979_t7 = ((int64_t*)&_980_x + _979_t6);
    _979_t8 = 4;
    _980_y = (struct1) {_979_t7, _979_t8};
    _979_t9 = _981_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _979_t10 = _979_t9(_980_y);
    $line_idx--;
    _979_$retval = _979_t10;
    return _979_$retval;
}

int64_t _981_f(struct1 _981_x) {
    int64_t _981_t0;
    int64_t _981_t1;
    int64_t _981_$retval;
    _981_t0 = 1;
    _981_t1 = 80;
    _981_$retval = $add_int64_t(*((int64_t*)_981_x._0 + _981_t0), _981_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _981_$retval;
}

int main(void) {
  printf("%ld",_979_main());
  return 0;
}
