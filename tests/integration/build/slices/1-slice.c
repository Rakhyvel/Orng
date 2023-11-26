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
int64_t _2_main(void);
int64_t _4_first(struct1 _4_xs);

/* Function definitions */
int64_t _2_main(void) {
    function0 _2_t0;
    int64_t _2_t3;
    int64_t _2_t5;
    struct2 _2_t4;
    int64_t* _2_t6;
    int64_t _2_t7;
    struct1 _2_t2;
    int64_t _2_t1;
    int64_t _2_$retval;
    _2_t0 = _4_first;
    _2_t3 = 0;
    _2_t5 = 233;
    _2_t4 = (struct2) {_2_t5};
    _2_t6 = ((int64_t*)&_2_t4 + _2_t3);
    _2_t7 = 1;
    _2_t2 = (struct1) {_2_t6, _2_t7};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _2_t1 = _2_t0(_2_t2);
    $line_idx--;
    _2_$retval = _2_t1;
    return _2_$retval;
}

int64_t _4_first(struct1 _4_xs) {
    int64_t _4_t0;
    int64_t _4_$retval;
    _4_t0 = 0;
    _4_$retval = *((int64_t*)_4_xs._0 + _4_t0);
    return _4_$retval;
}

int main(void) {
  printf("%ld",_2_main());
  return 0;
}
