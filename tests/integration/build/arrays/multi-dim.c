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
    struct0 _2;
} struct1;

/* Function forward definitions */
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t1;
    struct0 _1_t5;
    struct0 _1_t9;
    struct1 _2_x;
    int64_t _1_$retval;
    _1_t1 = (struct0) {1, 2, 3};
    _1_t5 = (struct0) {4, 5, 68};
    _1_t9 = (struct0) {7, 8, 9};
    _2_x = (struct1) {_1_t1, _1_t5, _1_t9};
    *((int64_t*)((struct0*)&_2_x + 1) + 2) = $add_int64_t(*((int64_t*)((struct0*)&_2_x + 1) + 2), 1, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    _1_$retval = *((int64_t*)((struct0*)&_2_x + 1) + 2);
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
