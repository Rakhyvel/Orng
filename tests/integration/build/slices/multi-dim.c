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
    int64_t* _0;
    int64_t _1;
} struct1;

typedef struct {
    struct1 _0;
    struct1 _1;
    struct1 _2;
} struct2;

typedef struct {
    struct1* _0;
    int64_t _1;
} struct3;

/* Function forward definitions */
int64_t _1_main();

/* Function definitions */
int64_t _1_main() {
    struct0 _2_x;
    int64_t* _1_t9;
    struct1 _1_t5;
    int64_t* _1_t15;
    struct1 _1_t11;
    int64_t* _1_t21;
    struct1 _1_t17;
    struct2 _2_y;
    struct1* _1_t27;
    struct3 _2_z;
    int64_t _1_$retval;
    _2_x = (struct0) {1, 2, 3};
    _1_t9 = (int64_t*)&_2_x;
    _1_t5 = (struct1) {_1_t9, 3};
    _1_t15 = (int64_t*)&_2_x;
    _1_t11 = (struct1) {_1_t15, 3};
    _1_t21 = (int64_t*)&_2_x;
    _1_t17 = (struct1) {_1_t21, 3};
    _2_y = (struct2) {_1_t5, _1_t11, _1_t17};
    _1_t27 = (struct1*)&_2_y;
    _2_z = (struct3) {_1_t27, 3};
    $bounds_check(2, ((struct1*)_2_z._0 + 1)->_1, "tests/integration/slices/multi-dim.orng:6:10:\n    z[1][2] = 82\n        ^");
    *((int64_t*)((struct1*)_2_z._0 + 1)->_0 + 2) = 82;
    $bounds_check(2, ((struct1*)_2_z._0 + 1)->_1, "tests/integration/slices/multi-dim.orng:7:10:\n    z[1][2]\n        ^");
    _1_$retval = *((int64_t*)((struct1*)_2_z._0 + 1)->_0 + 2);
    return _1_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
