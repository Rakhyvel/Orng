/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;
struct struct2;

/* Typedefs */
struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function0)(struct struct1);

struct struct2 {
    int64_t _0;
};

/* Function forward definitions */
int64_t _1293_main(void);
int64_t _1295_first(struct struct1 _1295_xs);

/* Function definitions */
int64_t _1293_main(void){
    function0 _1293_t0;
    int64_t _1293_t4;
    struct struct2 _1293_t3;
    int64_t _1293_t5;
    int64_t _1293_t6;
    int64_t* _1293_t7;
    int64_t _1293_t8;
    struct struct1 _1293_t2;
    int64_t _1293_t1;
    int64_t _1293_$retval;
    _1293_t0 = _1295_first;
    _1293_t4 = 233;
    _1293_t3 = (struct struct2) {_1293_t4};
    _1293_t5 = 0;
    _1293_t6 = 1;
    $bounds_check(_1293_t5, _1293_t6, "tests/integration/slices/1-slice.orng:3:18:\n    first([](233,))\n                ^");
    _1293_t7 = ((int64_t*)&_1293_t3 + _1293_t5);
    _1293_t8 = 1;
    _1293_t2 = (struct struct1) {_1293_t7, _1293_t8};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _1293_t1 = _1293_t0(_1293_t2);
    $line_idx--;
    _1293_$retval = _1293_t1;
    return _1293_$retval;
}

int64_t _1295_first(struct struct1 _1295_xs){
    int64_t _1295_t0;
    int64_t _1295_$retval;
    _1295_t0 = 0;
    $bounds_check(_1295_t0, _1295_xs._1, "tests/integration/slices/1-slice.orng:6:3:\nfn first(xs: []Int) -> Int {\n ^");
    _1295_$retval = *((int64_t*)_1295_xs._0 + _1295_t0);
    return _1295_$retval;
}

int main(void) {
  printf("%ld",_1293_main());
  return 0;
}
