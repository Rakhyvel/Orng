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
} struct0;

typedef struct {
    int64_t _0;
    int64_t _2;
} struct1;

/* Function forward definitions */
int64_t _1207_main(void);

/* Function definitions */
int64_t _1207_main(void){
    int64_t _1207_t1;
    int64_t _1207_t2;
    struct0 _1207_t0;
    int64_t _1208_x;
    int64_t _1208_y;
    int64_t _1207_t4;
    int64_t _1207_t6;
    struct1 _1207_t3;
    int64_t _1207_$retval;
    _1207_t1 = 0;
    _1207_t2 = 0;
    _1207_t0 = (struct0) {_1207_t1, _1207_t2};
    _1208_x = _1207_t0._0;
    _1208_y = _1207_t0._1;
    _1207_t4 = 5;
    _1207_t6 = 33;
    _1207_t3 = (struct1) {_1207_t4, _1207_t6};
    _1208_x = _1207_t3._0;
    _1208_y = _1207_t3._2;
    _1207_$retval = $mult_int64_t(_1208_x, _1208_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _1207_$retval;
}

int main(void) {
  printf("%ld",_1207_main());
  return 0;
}
