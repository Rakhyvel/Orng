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
int64_t _1394_main(void);
int64_t _1396_f(struct1 _1396_x);

/* Function definitions */
int64_t _1394_main(void){
    int64_t _1394_t1;
    int64_t _1394_t2;
    int64_t _1394_t3;
    int64_t _1394_t4;
    struct0 _1395_x;
    int64_t _1394_t6;
    int64_t _1394_t7;
    int64_t* _1394_t8;
    int64_t _1394_t9;
    struct1 _1395_y;
    function2 _1394_t10;
    int64_t _1394_t11;
    int64_t _1394_$retval;
    _1394_t1 = 1;
    _1394_t2 = 2;
    _1394_t3 = 3;
    _1394_t4 = 4;
    _1395_x = (struct0) {_1394_t1, _1394_t2, _1394_t3, _1394_t4};
    _1394_t6 = 0;
    _1394_t7 = 4;
    $bounds_check(_1394_t6, _1394_t7, "tests/integration/slices/fn-pass.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1394_t8 = ((int64_t*)&_1395_x + _1394_t6);
    _1394_t9 = 4;
    _1395_y = (struct1) {_1394_t8, _1394_t9};
    _1394_t10 = _1396_f;
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _1394_t11 = _1394_t10(_1395_y);
    $line_idx--;
    _1394_$retval = _1394_t11;
    return _1394_$retval;
}

int64_t _1396_f(struct1 _1396_x){
    int64_t _1396_t0;
    int64_t _1396_t1;
    int64_t _1396_$retval;
    _1396_t0 = 1;
    _1396_t1 = 80;
    $bounds_check(_1396_t0, _1396_x._1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    _1396_$retval = $add_int64_t(*((int64_t*)_1396_x._0 + _1396_t0), _1396_t1, "tests/integration/slices/fn-pass.orng:8:28:\nfn f(x: []Int)->Int {x[1] + 80}\n                          ^");
    return _1396_$retval;
}

int main(void) {
  printf("%ld",_1394_main());
  return 0;
}
