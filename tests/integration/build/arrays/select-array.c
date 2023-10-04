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
} struct0;

typedef struct {
    struct0 _0;
    struct0 _1;
} struct1;

/* Function forward definitions */
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t1;
    struct0 _1_t5;
    struct1 _2_x;
    int64_t _1_$retval;
    _1_t1 = (struct0) {1, 2, 3};
    _1_t5 = (struct0) {4, 5, 6};
    _2_x = (struct1) {_1_t1, _1_t5};
    *((int64_t*)&_2_x._0 + 1) = 72;
    _1_$retval = *((int64_t*)&_2_x._0 + 1);
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
