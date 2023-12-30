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

typedef int64_t(*function0)(struct1);

/* Function forward definitions */
int64_t _997_main(void);
int64_t _999_add(struct1 _999_x);

/* Function definitions */
int64_t _997_main(void){
    function0 _997_t0;
    int64_t _997_t3;
    int64_t _997_t4;
    int64_t _997_t5;
    struct1 _997_t2;
    int64_t _997_t1;
    int64_t _997_$retval;
    _997_t0 = _999_add;
    _997_t3 = 100;
    _997_t4 = 90;
    _997_t5 = 7;
    _997_t2 = (struct1) {_997_t3, _997_t4, _997_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _997_t1 = _997_t0(_997_t2);
    $line_idx--;
    _997_$retval = _997_t1;
    return _997_$retval;
}

int64_t _999_add(struct1 _999_x){
    int64_t _999_t0;
    int64_t _999_t1;
    int64_t _999_t2;
    int64_t _999_t3;
    int64_t _999_t4;
    int64_t _999_t5;
    int64_t _999_t6;
    int64_t _999_$retval;
    _999_t0 = 0;
    _999_t1 = 3;
    _999_t2 = 1;
    _999_t3 = 3;
    $bounds_check(_999_t0, _999_t1, "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    $bounds_check(_999_t2, _999_t3, "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _999_t4 = $add_int64_t(*((int64_t*)&_999_x + _999_t0), *((int64_t*)&_999_x + _999_t2), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _999_t5 = 2;
    _999_t6 = 3;
    $bounds_check(_999_t5, _999_t6, "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    _999_$retval = $add_int64_t(_999_t4, *((int64_t*)&_999_x + _999_t5), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _999_$retval;
}

int main(void) {
  printf("%ld",_997_main());
  return 0;
}
