/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function0)(struct struct1);

struct struct2 {
    int64_t _0;
};

/* Function forward definitions */
int64_t _1432_main(void);
int64_t _1434_first(struct struct1 _1434_xs);


/* Function definitions */
int64_t _1432_main(void){
    function0 _1432_t0;
    int64_t _1432_t4;
    struct struct2 _1432_t3;
    int64_t _1432_t5;
    int64_t _1432_t6;
    int64_t* _1432_t7;
    int64_t _1432_t8;
    struct struct1 _1432_t2;
    int64_t _1432_t1;
    int64_t _1432_$retval;
    _1432_t0 = (function0) _1434_first;
    _1432_t4 = 233;
    _1432_t3 = (struct struct2) {_1432_t4};
    _1432_t5 = 0;
    _1432_t6 = 1;
    $bounds_check(_1432_t5, _1432_t6, "tests/integration/slices/1-slice.orng:3:18:\n    first([](233,))\n                ^");
    _1432_t7 = ((int64_t*)&_1432_t3 + _1432_t5);
    _1432_t8 = 1;
    _1432_t2 = (struct struct1) {_1432_t7, _1432_t8};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _1432_t1 = _1432_t0(_1432_t2);
    $line_idx--;
    _1432_$retval = _1432_t1;
    return _1432_$retval;
}

int64_t _1434_first(struct struct1 _1434_xs){
    int64_t _1434_t0;
    int64_t _1434_$retval;
    _1434_t0 = 0;
    $bounds_check(_1434_t0, _1434_xs._1, "tests/integration/slices/1-slice.orng:6:9:\nfn first(xs: []Int) -> Int {\n       ^");
    _1434_$retval = *((int64_t*)_1434_xs._0 + _1434_t0);
    return _1434_$retval;
}


int main(void) {
  printf("%ld",_1432_main());
  return 0;
}
