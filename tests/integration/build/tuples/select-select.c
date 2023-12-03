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
int64_t _1146_main(void);

/* Function definitions */
int64_t _1146_main(void) {
    int64_t _1146_t2;
    int64_t _1146_t3;
    struct0 _1146_t1;
    int64_t _1146_t5;
    int64_t _1146_t6;
    struct0 _1146_t4;
    struct1 _1147_x;
    int64_t _1146_$retval;
    _1146_t2 = 1;
    _1146_t3 = 2;
    _1146_t1 = (struct0) {_1146_t2, _1146_t3};
    _1146_t5 = 3;
    _1146_t6 = 4;
    _1146_t4 = (struct0) {_1146_t5, _1146_t6};
    _1147_x = (struct1) {_1146_t1, _1146_t4};
    _1147_x._0._0 = 77;
    _1146_$retval = _1147_x._0._0;
    return _1146_$retval;
}

int main(void) {
  printf("%ld",_1146_main());
  return 0;
}
