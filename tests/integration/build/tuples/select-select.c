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
int64_t _1551_main(void);

/* Function definitions */
int64_t _1551_main(void) {
    int64_t _1551_t2;
    int64_t _1551_t3;
    struct0 _1551_t1;
    int64_t _1551_t5;
    int64_t _1551_t6;
    struct0 _1551_t4;
    struct1 _1552_x;
    int64_t _1551_$retval;
    _1551_t2 = 1;
    _1551_t3 = 2;
    _1551_t1 = (struct0) {_1551_t2, _1551_t3};
    _1551_t5 = 3;
    _1551_t6 = 4;
    _1551_t4 = (struct0) {_1551_t5, _1551_t6};
    _1552_x = (struct1) {_1551_t1, _1551_t4};
    _1552_x._0._0 = 77;
    _1551_$retval = _1552_x._0._0;
    return _1551_$retval;
}

int main(void) {
  printf("%ld",_1551_main());
  return 0;
}
