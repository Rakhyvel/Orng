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
int64_t _984_main(void);
int64_t _986_add(struct1 _986_x);

/* Function definitions */
int64_t _984_main(void){
    function0 _984_t0;
    int64_t _984_t3;
    int64_t _984_t4;
    int64_t _984_t5;
    struct1 _984_t2;
    int64_t _984_t1;
    int64_t _984_$retval;
    _984_t0 = _986_add;
    _984_t3 = 100;
    _984_t4 = 90;
    _984_t5 = 7;
    _984_t2 = (struct1) {_984_t3, _984_t4, _984_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _984_t1 = _984_t0(_984_t2);
    $line_idx--;
    _984_$retval = _984_t1;
    return _984_$retval;
}

int64_t _986_add(struct1 _986_x){
    int64_t _986_t0;
    int64_t _986_t1;
    int64_t _986_t2;
    int64_t _986_t3;
    int64_t _986_t4;
    int64_t _986_t5;
    int64_t _986_t6;
    int64_t _986_$retval;
    _986_t0 = 0;
    _986_t1 = 3;
    _986_t2 = 1;
    _986_t3 = 3;
    $bounds_check(_986_t0, _986_t1, "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    $bounds_check(_986_t2, _986_t3, "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _986_t4 = $add_int64_t(*((int64_t*)&_986_x + _986_t0), *((int64_t*)&_986_x + _986_t2), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _986_t5 = 2;
    _986_t6 = 3;
    $bounds_check(_986_t5, _986_t6, "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    _986_$retval = $add_int64_t(_986_t4, *((int64_t*)&_986_x + _986_t5), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _986_$retval;
}

int main(void) {
  printf("%ld",_984_main());
  return 0;
}
