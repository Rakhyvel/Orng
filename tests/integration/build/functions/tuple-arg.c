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
int64_t _1027_main(void);
int64_t _1029_add(struct struct1 _1029_x);


/* Function definitions */
int64_t _1027_main(void){
    function0 _1027_t0;
    int64_t _1027_t3;
    int64_t _1027_t4;
    int64_t _1027_t5;
    struct struct1 _1027_t2;
    int64_t _1027_t1;
    int64_t _1027_$retval;
    _1027_t0 = (function0) _1029_add;
    _1027_t3 = 100;
    _1027_t4 = 90;
    _1027_t5 = 7;
    _1027_t2 = (struct struct1) {_1027_t3, _1027_t4, _1027_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _1027_t1 = _1027_t0(_1027_t2);
    $line_idx--;
    _1027_$retval = _1027_t1;
    return _1027_$retval;
}

int64_t _1029_add(struct struct1 _1029_x){
    int64_t _1029_t0;
    int64_t _1029_t1;
    int64_t _1029_t2;
    int64_t _1029_t3;
    int64_t _1029_t4;
    int64_t _1029_t5;
    int64_t _1029_t6;
    int64_t _1029_$retval;
    _1029_t0 = 0;
    _1029_t1 = 3;
    _1029_t2 = 1;
    _1029_t3 = 3;
    $bounds_check(_1029_t0, _1029_t1, "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    $bounds_check(_1029_t2, _1029_t3, "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1029_t4 = $add_int64_t(*((int64_t*)&_1029_x + _1029_t0), *((int64_t*)&_1029_x + _1029_t2), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1029_t5 = 2;
    _1029_t6 = 3;
    $bounds_check(_1029_t5, _1029_t6, "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    _1029_$retval = $add_int64_t(_1029_t4, *((int64_t*)&_1029_x + _1029_t5), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _1029_$retval;
}


int main(void) {
  printf("%ld",_1027_main());
  return 0;
}
