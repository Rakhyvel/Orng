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

typedef int64_t(*function0)(struct struct1);

/* Function forward definitions */
int64_t _1008_main(void);
int64_t _1010_add(struct struct1 _1010_x);


/* Function definitions */
int64_t _1008_main(void){
    function0 _1008_t0;
    int64_t _1008_t3;
    int64_t _1008_t4;
    int64_t _1008_t5;
    struct struct1 _1008_t2;
    int64_t _1008_t1;
    int64_t _1008_$retval;
    _1008_t0 = (function0) _1010_add;
    _1008_t3 = 100;
    _1008_t4 = 90;
    _1008_t5 = 7;
    _1008_t2 = (struct struct1) {_1008_t3, _1008_t4, _1008_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _1008_t1 = _1008_t0(_1008_t2);
    $line_idx--;
    _1008_$retval = _1008_t1;
    return _1008_$retval;
}

int64_t _1010_add(struct struct1 _1010_x){
    int64_t _1010_t0;
    int64_t _1010_t1;
    int64_t _1010_t2;
    int64_t _1010_t3;
    int64_t _1010_t4;
    int64_t _1010_t5;
    int64_t _1010_t6;
    int64_t _1010_$retval;
    _1010_t0 = 0;
    _1010_t1 = 3;
    _1010_t2 = 1;
    _1010_t3 = 3;
    $bounds_check(_1010_t0, _1010_t1, "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    $bounds_check(_1010_t2, _1010_t3, "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1010_t4 = $add_int64_t(*((int64_t*)&_1010_x + _1010_t0), *((int64_t*)&_1010_x + _1010_t2), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1010_t5 = 2;
    _1010_t6 = 3;
    $bounds_check(_1010_t5, _1010_t6, "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    _1010_$retval = $add_int64_t(_1010_t4, *((int64_t*)&_1010_x + _1010_t5), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _1010_$retval;
}


int main(void) {
  printf("%ld",_1008_main());
  return 0;
}
