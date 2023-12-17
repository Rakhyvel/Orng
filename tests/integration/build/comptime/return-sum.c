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
struct0 _410_f(int64_t _410_x);
int64_t _403_main(void);

/* Function definitions */
struct0 _410_f(int64_t _410_x){
    int64_t _410_t1;
    uint8_t _410_t3;
    struct0 _410_t0;
    int64_t _410_t8;
    uint8_t _410_t10;
    int64_t _410_t4;
    int64_t _410_t5;
    struct0 _410_t7;
    struct0 _410_$retval;
    _410_t1 = 53;
    _410_t3 = _410_x == _410_t1;
    if (_410_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _410_t4 = 5;
    _410_t5 = $mult_int64_t(_410_x, _410_t4, "tests/integration/comptime/return-sum.orng:13:19:\n        .ok <- x * 5\n                 ^");
    _410_t0 = (struct0) {.tag=0, ._0=_410_t5};
    goto BB6;
BB7:
    _410_t8 = 4;
    _410_t10 = _410_x == _410_t8;
    if (_410_t10) {
        goto BB10;
    } else {
        goto BB13;
    }
BB6:
    _410_$retval = _410_t0;
    return _410_$retval;
BB10:
    _410_t7 = (struct0) {.tag=1};
    goto BB12;
BB13:
    _410_t7 = (struct0) {.tag=2};
    goto BB12;
BB12:
    _410_t0 = _410_t7;
    goto BB6;
}

int64_t _403_main(void){
    int64_t _403_t1;
    struct0 _403_t2;
    int64_t _403_$retval;
    _403_t1 = 265;
    _403_t2 = (struct0) {.tag=0, ._0=_403_t1};
    _403_$retval = _403_t2._0;
    return _403_$retval;
}

int main(void) {
  printf("%ld",_403_main());
  return 0;
}
