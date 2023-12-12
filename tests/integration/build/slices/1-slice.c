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
int64_t _974_main(void);
int64_t _976_first(struct1 _976_xs);

/* Function definitions */
int64_t _974_main(void) {
    function0 _974_t0;
    int64_t _974_t3;
    int64_t _974_t5;
    struct2 _974_t4;
    int64_t* _974_t6;
    int64_t _974_t7;
    struct1 _974_t2;
    int64_t _974_t1;
    int64_t _974_$retval;
    _974_t0 = _976_first;
    _974_t3 = 0;
    _974_t5 = 233;
    _974_t4 = (struct2) {_974_t5};
    _974_t6 = ((int64_t*)&_974_t4 + _974_t3);
    _974_t7 = 1;
    _974_t2 = (struct1) {_974_t6, _974_t7};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _974_t1 = _974_t0(_974_t2);
    $line_idx--;
    _974_$retval = _974_t1;
    return _974_$retval;
}

int64_t _976_first(struct1 _976_xs) {
    int64_t _976_t0;
    int64_t _976_$retval;
    _976_t0 = 0;
    _976_$retval = *((int64_t*)_976_xs._0 + _976_t0);
    return _976_$retval;
}

int main(void) {
  printf("%ld",_974_main());
  return 0;
}
