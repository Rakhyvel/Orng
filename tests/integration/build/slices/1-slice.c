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
int64_t _1476_main(void);
int64_t _1478_first(struct1 _1478_xs);

/* Function definitions */
int64_t _1476_main(void){
    function0 _1476_t0;
    int64_t _1476_t3;
    int64_t _1476_t5;
    struct2 _1476_t4;
    int64_t _1476_t6;
    int64_t* _1476_t7;
    int64_t _1476_t8;
    struct1 _1476_t2;
    int64_t _1476_t1;
    int64_t _1476_$retval;
    _1476_t0 = _1478_first;
    _1476_t3 = 0;
    _1476_t5 = 233;
    _1476_t4 = (struct2) {_1476_t5};
    _1476_t6 = 1;
    $bounds_check(_1476_t3, _1476_t6, "tests/integration/slices/1-slice.orng:3:18:\n    first([](233,))\n                ^");
    _1476_t7 = ((int64_t*)&_1476_t4 + _1476_t3);
    _1476_t8 = 1;
    _1476_t2 = (struct1) {_1476_t7, _1476_t8};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _1476_t1 = _1476_t0(_1476_t2);
    $line_idx--;
    _1476_$retval = _1476_t1;
    return _1476_$retval;
}

int64_t _1478_first(struct1 _1478_xs){
    int64_t _1478_t0;
    int64_t _1478_$retval;
    _1478_t0 = 0;
    $bounds_check(_1478_t0, _1478_xs._1, "tests/integration/slices/1-slice.orng:6:3:\nfn first(xs: []Int) -> Int {\n ^");
    _1478_$retval = *((int64_t*)_1478_xs._0 + _1478_t0);
    return _1478_$retval;
}

int main(void) {
  printf("%ld",_1476_main());
  return 0;
}
