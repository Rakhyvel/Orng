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
int64_t _1482_main(void);
int64_t _1484_first(struct1 _1484_xs);

/* Function definitions */
int64_t _1482_main(void){
    function0 _1482_t0;
    int64_t _1482_t3;
    int64_t _1482_t5;
    struct2 _1482_t4;
    int64_t _1482_t6;
    int64_t* _1482_t7;
    int64_t _1482_t8;
    struct1 _1482_t2;
    int64_t _1482_t1;
    int64_t _1482_$retval;
    _1482_t0 = _1484_first;
    _1482_t3 = 0;
    _1482_t5 = 233;
    _1482_t4 = (struct2) {_1482_t5};
    _1482_t6 = 1;
    $bounds_check(_1482_t3, _1482_t6, "tests/integration/slices/1-slice.orng:3:18:\n    first([](233,))\n                ^");
    _1482_t7 = ((int64_t*)&_1482_t4 + _1482_t3);
    _1482_t8 = 1;
    _1482_t2 = (struct1) {_1482_t7, _1482_t8};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _1482_t1 = _1482_t0(_1482_t2);
    $line_idx--;
    _1482_$retval = _1482_t1;
    return _1482_$retval;
}

int64_t _1484_first(struct1 _1484_xs){
    int64_t _1484_t0;
    int64_t _1484_$retval;
    _1484_t0 = 0;
    $bounds_check(_1484_t0, _1484_xs._1, "tests/integration/slices/1-slice.orng:6:3:\nfn first(xs: []Int) -> Int {\n ^");
    _1484_$retval = *((int64_t*)_1484_xs._0 + _1484_t0);
    return _1484_$retval;
}

int main(void) {
  printf("%ld",_1482_main());
  return 0;
}
