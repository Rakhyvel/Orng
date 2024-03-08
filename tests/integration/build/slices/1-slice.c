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
int64_t _1340_main(void);
int64_t _1342_first(struct struct1 _1342_xs);


/* Function definitions */
int64_t _1340_main(void){
    function0 _1340_t0;
    int64_t _1340_t4;
    struct struct2 _1340_t3;
    int64_t _1340_t5;
    int64_t _1340_t6;
    int64_t* _1340_t7;
    int64_t _1340_t8;
    struct struct1 _1340_t2;
    int64_t _1340_t1;
    int64_t _1340_$retval;
    _1340_t0 = (function0) _1342_first;
    _1340_t4 = 233;
    _1340_t3 = (struct struct2) {_1340_t4};
    _1340_t5 = 0;
    _1340_t6 = 1;
    $bounds_check(_1340_t5, _1340_t6, "tests/integration/slices/1-slice.orng:3:18:\n    first([](233,))\n                ^");
    _1340_t7 = ((int64_t*)&_1340_t3 + _1340_t5);
    _1340_t8 = 1;
    _1340_t2 = (struct struct1) {_1340_t7, _1340_t8};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _1340_t1 = _1340_t0(_1340_t2);
    $line_idx--;
    _1340_$retval = _1340_t1;
    return _1340_$retval;
}

int64_t _1342_first(struct struct1 _1342_xs){
    int64_t _1342_t0;
    int64_t _1342_$retval;
    _1342_t0 = 0;
    $bounds_check(_1342_t0, _1342_xs._1, "tests/integration/slices/1-slice.orng:6:3:\nfn first(xs: []Int) -> Int {\n ^");
    _1342_$retval = *((int64_t*)_1342_xs._0 + _1342_t0);
    return _1342_$retval;
}


int main(void) {
  printf("%ld",_1340_main());
  return 0;
}
