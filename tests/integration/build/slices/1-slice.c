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
int64_t _1308_main(void);
int64_t _1310_first(struct struct1 _1310_xs);

/* Function definitions */
int64_t _1308_main(void){
    function0 _1308_t0;
    int64_t _1308_t4;
    struct struct2 _1308_t3;
    int64_t _1308_t5;
    int64_t _1308_t6;
    int64_t* _1308_t7;
    int64_t _1308_t8;
    struct struct1 _1308_t2;
    int64_t _1308_t1;
    int64_t _1308_$retval;
    _1308_t0 = _1310_first;
    _1308_t4 = 233;
    _1308_t3 = (struct struct2) {_1308_t4};
    _1308_t5 = 0;
    _1308_t6 = 1;
    $bounds_check(_1308_t5, _1308_t6, "tests/integration/slices/1-slice.orng:3:18:\n    first([](233,))\n                ^");
    _1308_t7 = ((int64_t*)&_1308_t3 + _1308_t5);
    _1308_t8 = 1;
    _1308_t2 = (struct struct1) {_1308_t7, _1308_t8};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _1308_t1 = _1308_t0(_1308_t2);
    $line_idx--;
    _1308_$retval = _1308_t1;
    return _1308_$retval;
}

int64_t _1310_first(struct struct1 _1310_xs){
    int64_t _1310_t0;
    int64_t _1310_$retval;
    _1310_t0 = 0;
    $bounds_check(_1310_t0, _1310_xs._1, "tests/integration/slices/1-slice.orng:6:3:\nfn first(xs: []Int) -> Int {\n ^");
    _1310_$retval = *((int64_t*)_1310_xs._0 + _1310_t0);
    return _1310_$retval;
}

int main(void) {
  printf("%ld",_1308_main());
  return 0;
}
