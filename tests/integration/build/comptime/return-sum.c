/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _0;
    };
} struct0;

/* Function forward definitions */
struct0 _325_f(int64_t _325_x);
int64_t _318_main(void);

/* Function definitions */
struct0 _325_f(int64_t _325_x){
    int64_t _325_t1;
    uint8_t _325_t3;
    struct0 _325_t0;
    int64_t _325_t8;
    uint8_t _325_t10;
    int64_t _325_t4;
    int64_t _325_t5;
    struct0 _325_t7;
    struct0 _325_$retval;
    _325_t1 = 53;
    _325_t3 = _325_x == _325_t1;
    if (_325_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _325_t4 = 5;
    _325_t5 = $mult_int64_t(_325_x, _325_t4, "tests/integration/comptime/return-sum.orng:13:19:\n        .ok <- x * 5\n                 ^");
    _325_t0 = (struct0) {.tag=0, ._0=_325_t5};
    goto BB6;
BB7:
    _325_t8 = 4;
    _325_t10 = _325_x == _325_t8;
    if (_325_t10) {
        goto BB10;
    } else {
        goto BB13;
    }
BB6:
    _325_$retval = _325_t0;
    return _325_$retval;
BB10:
    _325_t7 = (struct0) {.tag=1};
    goto BB12;
BB13:
    _325_t7 = (struct0) {.tag=2};
    goto BB12;
BB12:
    _325_t0 = _325_t7;
    goto BB6;
}

int64_t _318_main(void){
    int64_t _318_t1;
    struct0 _318_t2;
    int64_t _318_$retval;
    _318_t1 = 265;
    _318_t2 = (struct0) {.tag=0, ._0=_318_t1};
    _318_$retval = _318_t2._0;
    return _318_$retval;
}

int main(void) {
  printf("%ld",_318_main());
  return 0;
}
