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
int64_t _42_main(void);

/* Function definitions */
int64_t _42_main(void) {
    int64_t _42_t2;
    int64_t _42_t3;
    struct0 _42_t1;
    int64_t _42_t5;
    int64_t _42_t6;
    struct0 _42_t4;
    struct1 _43_x;
    int64_t _42_$retval;
    _42_t2 = 1;
    _42_t3 = 2;
    _42_t1 = (struct0) {_42_t2, _42_t3};
    _42_t5 = 3;
    _42_t6 = 4;
    _42_t4 = (struct0) {_42_t5, _42_t6};
    _43_x = (struct1) {_42_t1, _42_t4};
    _43_x._0._0 = 77;
    _42_$retval = _43_x._0._0;
    return _42_$retval;
}

int main(void) {
  printf("%ld",_42_main());
  return 0;
}
