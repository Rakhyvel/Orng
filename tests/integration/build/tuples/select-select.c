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
int64_t _1077_main(void);

/* Function definitions */
int64_t _1077_main(void) {
    int64_t _1077_t2;
    int64_t _1077_t3;
    struct0 _1077_t1;
    int64_t _1077_t5;
    int64_t _1077_t6;
    struct0 _1077_t4;
    struct1 _1078_x;
    int64_t _1077_$retval;
    _1077_t2 = 1;
    _1077_t3 = 2;
    _1077_t1 = (struct0) {_1077_t2, _1077_t3};
    _1077_t5 = 3;
    _1077_t6 = 4;
    _1077_t4 = (struct0) {_1077_t5, _1077_t6};
    _1078_x = (struct1) {_1077_t1, _1077_t4};
    _1078_x._0._0 = 77;
    _1077_$retval = _1078_x._0._0;
    return _1077_$retval;
}

int main(void) {
  printf("%ld",_1077_main());
  return 0;
}
