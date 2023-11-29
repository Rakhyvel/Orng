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
    struct0 _0;
    struct0 _1;
} struct1;

/* Function forward definitions */
int64_t _45_main(void);

/* Function definitions */
int64_t _45_main(void) {
    int64_t _45_t2;
    int64_t _45_t3;
    struct0 _45_t1;
    int64_t _45_t5;
    int64_t _45_t6;
    struct0 _45_t4;
    struct1 _46_x;
    int64_t _45_$retval;
    _45_t2 = 1;
    _45_t3 = 2;
    _45_t1 = (struct0) {_45_t2, _45_t3};
    _45_t5 = 3;
    _45_t6 = 4;
    _45_t4 = (struct0) {_45_t5, _45_t6};
    _46_x = (struct1) {_45_t1, _45_t4};
    _46_x._0._0 = 77;
    _45_$retval = _46_x._0._0;
    return _45_$retval;
}

int main(void) {
  printf("%ld",_45_main());
  return 0;
}
