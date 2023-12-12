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
int64_t _993_main(void);
int64_t _995_first(struct1 _995_xs);

/* Function definitions */
int64_t _993_main(void) {
    function0 _993_t0;
    int64_t _993_t3;
    int64_t _993_t5;
    struct2 _993_t4;
    int64_t* _993_t6;
    int64_t _993_t7;
    struct1 _993_t2;
    int64_t _993_t1;
    int64_t _993_$retval;
    _993_t0 = _995_first;
    _993_t3 = 0;
    _993_t5 = 233;
    _993_t4 = (struct2) {_993_t5};
    _993_t6 = ((int64_t*)&_993_t4 + _993_t3);
    _993_t7 = 1;
    _993_t2 = (struct1) {_993_t6, _993_t7};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _993_t1 = _993_t0(_993_t2);
    $line_idx--;
    _993_$retval = _993_t1;
    return _993_$retval;
}

int64_t _995_first(struct1 _995_xs) {
    int64_t _995_t0;
    int64_t _995_$retval;
    _995_t0 = 0;
    _995_$retval = *((int64_t*)_995_xs._0 + _995_t0);
    return _995_$retval;
}

int main(void) {
  printf("%ld",_993_main());
  return 0;
}
