/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

typedef int64_t(*function0)(struct1);

typedef struct {
    int64_t _0;
} struct2;

/* Function forward definitions */
int64_t _907_main(void);
int64_t _909_first(struct1 _909_xs);

/* Function definitions */
int64_t _907_main(void) {
    function0 _907_t0;
    int64_t _907_t3;
    int64_t _907_t5;
    struct2 _907_t4;
    int64_t* _907_t6;
    int64_t _907_t7;
    struct1 _907_t2;
    int64_t _907_t1;
    int64_t _907_$retval;
    _907_t0 = _909_first;
    _907_t3 = 0;
    _907_t5 = 233;
    _907_t4 = (struct2) {_907_t5};
    _907_t6 = ((int64_t*)&_907_t4 + _907_t3);
    _907_t7 = 1;
    _907_t2 = (struct1) {_907_t6, _907_t7};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _907_t1 = _907_t0(_907_t2);
    $line_idx--;
    _907_$retval = _907_t1;
    return _907_$retval;
}

int64_t _909_first(struct1 _909_xs) {
    int64_t _909_t0;
    int64_t _909_$retval;
    _909_t0 = 0;
    _909_$retval = *((int64_t*)_909_xs._0 + _909_t0);
    return _909_$retval;
}

int main(void) {
  printf("%ld",_907_main());
  return 0;
}
