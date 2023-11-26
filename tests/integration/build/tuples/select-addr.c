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

/* Function forward definitions */
int64_t _35_main(void);

/* Function definitions */
int64_t _35_main(void) {
    int64_t _35_t1;
    int64_t _35_t2;
    struct0 _36_x;
    struct0* _35_t4;
    struct0* _35_t5;
    int64_t _35_$retval;
    _35_t1 = 1;
    _35_t2 = 2;
    _36_x = (struct0) {_35_t1, _35_t2};
    _35_t4 = &_36_x;
    (*_35_t4)._0 = 76;
    _35_t5 = &_36_x;
    _35_$retval = (*_35_t5)._0;
    return _35_$retval;
}

int main(void) {
  printf("%ld",_35_main());
  return 0;
}
