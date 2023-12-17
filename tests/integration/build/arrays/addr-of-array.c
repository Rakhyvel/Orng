/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
} struct1;

typedef int64_t(*function0)(struct1*);

/* Function forward definitions */
int64_t _18_main(void);
int64_t _20_sum(struct1* _20_xs);

/* Function definitions */
int64_t _18_main(void){
    function0 _18_t0;
    int64_t _18_t3;
    int64_t _18_t4;
    int64_t _18_t5;
    struct1 _18_t2;
    struct1* _18_t6;
    int64_t _18_t1;
    int64_t _18_$retval;
    _18_t0 = _20_sum;
    _18_t3 = 200;
    _18_t4 = 0;
    _18_t5 = 9;
    _18_t2 = (struct1) {_18_t3, _18_t4, _18_t5};
    _18_t6 = &_18_t2;
    $lines[$line_idx++] = "tests/integration/arrays/addr-of-array.orng:3:9:\n    sum(&(200, 0, 9)) // Address of product literal\n       ^";
    _18_t1 = _18_t0(_18_t6);
    $line_idx--;
    _18_$retval = _18_t1;
    return _18_$retval;
}

int64_t _20_sum(struct1* _20_xs){
    int64_t _20_t0;
    int64_t _20_t1;
    int64_t _20_t2;
    int64_t _20_t3;
    int64_t _20_t4;
    int64_t _20_t5;
    int64_t _20_t6;
    int64_t _20_$retval;
    _20_t0 = 0;
    _20_t1 = 3;
    _20_t2 = 1;
    _20_t3 = 3;
    $bounds_check(_20_t0, _20_t1, "tests/integration/arrays/addr-of-array.orng:7:12:\n    xs[0] + xs[1] + xs[2]\n          ^");
    $bounds_check(_20_t2, _20_t3, "tests/integration/arrays/addr-of-array.orng:7:12:\n    xs[0] + xs[1] + xs[2]\n          ^");
    _20_t4 = $add_int64_t(*((int64_t*)_20_xs + _20_t0), *((int64_t*)_20_xs + _20_t2), "tests/integration/arrays/addr-of-array.orng:7:12:\n    xs[0] + xs[1] + xs[2]\n          ^");
    _20_t5 = 2;
    _20_t6 = 3;
    $bounds_check(_20_t5, _20_t6, "tests/integration/arrays/addr-of-array.orng:7:20:\n    xs[0] + xs[1] + xs[2]\n                  ^");
    _20_$retval = $add_int64_t(_20_t4, *((int64_t*)_20_xs + _20_t5), "tests/integration/arrays/addr-of-array.orng:7:20:\n    xs[0] + xs[1] + xs[2]\n                  ^");
    return _20_$retval;
}

int main(void) {
  printf("%ld",_18_main());
  return 0;
}
