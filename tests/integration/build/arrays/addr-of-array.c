/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

typedef int64_t(*function0)(struct struct1*);

/* Function forward definitions */
int64_t _20_main(void);
int64_t _22_sum(struct struct1* _22_xs);


/* Function definitions */
int64_t _20_main(void){
    function0 _20_t0;
    int64_t _20_t3;
    int64_t _20_t4;
    int64_t _20_t5;
    struct struct1 _20_t2;
    struct struct1* _20_t6;
    int64_t _20_t1;
    int64_t _20_$retval;
    _20_t0 = (function0) _22_sum;
    _20_t3 = 200;
    _20_t4 = 0;
    _20_t5 = 9;
    _20_t2 = (struct struct1) {_20_t3, _20_t4, _20_t5};
    _20_t6 = &_20_t2;
    $lines[$line_idx++] = "tests/integration/arrays/addr-of-array.orng:3:9:\n    sum(&(200, 0, 9)) // Address of product literal\n       ^";
    _20_t1 = _20_t0(_20_t6);
    $line_idx--;
    _20_$retval = _20_t1;
    return _20_$retval;
}

int64_t _22_sum(struct struct1* _22_xs){
    int64_t _22_t0;
    int64_t _22_t1;
    int64_t _22_t2;
    int64_t _22_t3;
    int64_t _22_t4;
    int64_t _22_t5;
    int64_t _22_t6;
    int64_t _22_$retval;
    _22_t0 = 0;
    _22_t1 = 3;
    _22_t2 = 1;
    _22_t3 = 3;
    $bounds_check(_22_t0, _22_t1, "tests/integration/arrays/addr-of-array.orng:7:12:\n    xs[0] + xs[1] + xs[2]\n          ^");
    $bounds_check(_22_t2, _22_t3, "tests/integration/arrays/addr-of-array.orng:7:12:\n    xs[0] + xs[1] + xs[2]\n          ^");
    _22_t4 = $add_int64_t(*((int64_t*)_22_xs + _22_t0), *((int64_t*)_22_xs + _22_t2), "tests/integration/arrays/addr-of-array.orng:7:12:\n    xs[0] + xs[1] + xs[2]\n          ^");
    _22_t5 = 2;
    _22_t6 = 3;
    $bounds_check(_22_t5, _22_t6, "tests/integration/arrays/addr-of-array.orng:7:20:\n    xs[0] + xs[1] + xs[2]\n                  ^");
    _22_$retval = $add_int64_t(_22_t4, *((int64_t*)_22_xs + _22_t5), "tests/integration/arrays/addr-of-array.orng:7:20:\n    xs[0] + xs[1] + xs[2]\n                  ^");
    return _22_$retval;
}


int main(void) {
  printf("%ld",_20_main());
  return 0;
}
