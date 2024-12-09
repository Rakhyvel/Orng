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
int64_t _16_main(void);
int64_t _18_sum(struct struct1* _18_xs);


/* Function definitions */
int64_t _16_main(void){
    function0 _16_t0;
    int64_t _16_t3;
    int64_t _16_t4;
    int64_t _16_t5;
    struct struct1 _16_t2;
    struct struct1* _16_t6;
    int64_t _16_t1;
    int64_t _16_$retval;
    _16_t0 = (function0) _18_sum;
    _16_t3 = 200;
    _16_t4 = 0;
    _16_t5 = 9;
    _16_t2 = (struct struct1) {_16_t3, _16_t4, _16_t5};
    _16_t6 = &_16_t2;
    $lines[$line_idx++] = "tests/integration/arrays/addr-of-array.orng:3:9:\n    sum(&(200, 0, 9)) // Address of product literal\n       ^";
    _16_t1 = _16_t0(_16_t6);
    $line_idx--;
    _16_$retval = _16_t1;
    return _16_$retval;
}

int64_t _18_sum(struct struct1* _18_xs){
    int64_t _18_t0;
    int64_t _18_t1;
    int64_t _18_t2;
    int64_t _18_t3;
    int64_t _18_t4;
    int64_t _18_t5;
    int64_t _18_t6;
    int64_t _18_$retval;
    _18_t0 = 0;
    _18_t1 = 3;
    _18_t2 = 1;
    _18_t3 = 3;
    $bounds_check(_18_t0, _18_t1, "tests/integration/arrays/addr-of-array.orng:7:12:\n    xs[0] + xs[1] + xs[2]\n          ^");
    $bounds_check(_18_t2, _18_t3, "tests/integration/arrays/addr-of-array.orng:7:12:\n    xs[0] + xs[1] + xs[2]\n          ^");
    _18_t4 = $add_int64_t(*((int64_t*)_18_xs + _18_t0), *((int64_t*)_18_xs + _18_t2), "tests/integration/arrays/addr-of-array.orng:7:12:\n    xs[0] + xs[1] + xs[2]\n          ^");
    _18_t5 = 2;
    _18_t6 = 3;
    $bounds_check(_18_t5, _18_t6, "tests/integration/arrays/addr-of-array.orng:7:20:\n    xs[0] + xs[1] + xs[2]\n                  ^");
    _18_$retval = $add_int64_t(_18_t4, *((int64_t*)_18_xs + _18_t5), "tests/integration/arrays/addr-of-array.orng:7:20:\n    xs[0] + xs[1] + xs[2]\n                  ^");
    return _18_$retval;
}


int main(void) {
  printf("%ld",_16_main());
  return 0;
}
