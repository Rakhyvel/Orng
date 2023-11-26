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
int64_t _881_main(void);
int64_t _883_f(struct1 _883_x);

/* Function definitions */
int64_t _881_main(void) {
    int64_t _881_t1;
    int64_t _881_t2;
    int64_t _881_t3;
    int64_t _881_t4;
    struct0 _882_x;
    int64_t _881_t6;
    int64_t* _881_t7;
    int64_t _881_t8;
    struct1 _882_y;
    function2 _881_t9;
    int64_t _881_t10;
    int64_t _881_$retval;
    _881_t1 = 1;
    _881_t2 = 2;
    _881_t3 = 3;
    _881_t4 = 4;
    _882_x = (struct0) {_881_t1, _881_t2, _881_t3, _881_t4};
    _881_t6 = 0;
    _881_t7 = ((int64_t*)&_882_x + _881_t6);
    _881_t8 = 4;
    _882_y = (struct1) {_881_t7, _881_t8};
    _881_t9 = _883_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _881_t10 = _881_t9(_882_y);
    $line_idx--;
    _881_$retval = _881_t10;
    return _881_$retval;
}

int64_t _883_f(struct1 _883_x) {
    int64_t _883_t0;
    int64_t _883_t1;
    int64_t _883_$retval;
    _883_t0 = 1;
    _883_t1 = 80;
    _883_$retval = $add_int64_t(*((int64_t*)_883_x._0 + _883_t0), _883_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _883_$retval;
}

int main(void) {
  printf("%ld",_881_main());
  return 0;
}
