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
int64_t _1402_main(void);
int64_t _1404_first(struct struct1 _1404_xs);


/* Function definitions */
int64_t _1402_main(void){
    function0 _1402_t0;
    int64_t _1402_t4;
    struct struct2 _1402_t3;
    int64_t _1402_t5;
    int64_t _1402_t6;
    int64_t* _1402_t7;
    int64_t _1402_t8;
    struct struct1 _1402_t2;
    int64_t _1402_t1;
    int64_t _1402_$retval;
    _1402_t0 = (function0) _1404_first;
    _1402_t4 = 233;
    _1402_t3 = (struct struct2) {_1402_t4};
    _1402_t5 = 0;
    _1402_t6 = 1;
    $bounds_check(_1402_t5, _1402_t6, "tests/integration/slices/1-slice.orng:3:18:\n    first([](233,))\n                ^");
    _1402_t7 = ((int64_t*)&_1402_t3 + _1402_t5);
    _1402_t8 = 1;
    _1402_t2 = (struct struct1) {_1402_t7, _1402_t8};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _1402_t1 = _1402_t0(_1402_t2);
    $line_idx--;
    _1402_$retval = _1402_t1;
    return _1402_$retval;
}

int64_t _1404_first(struct struct1 _1404_xs){
    int64_t _1404_t0;
    int64_t _1404_$retval;
    _1404_t0 = 0;
    $bounds_check(_1404_t0, _1404_xs._1, "tests/integration/slices/1-slice.orng:6:9:\nfn first(xs: []Int) -> Int {\n       ^");
    _1404_$retval = *((int64_t*)_1404_xs._0 + _1404_t0);
    return _1404_$retval;
}


int main(void) {
  printf("%ld",_1402_main());
  return 0;
}
