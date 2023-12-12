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
int64_t _768_main(void);
int64_t _770_add(struct1 _770_x);

/* Function definitions */
int64_t _768_main(void) {
    function0 _768_t0;
    int64_t _768_t3;
    int64_t _768_t4;
    int64_t _768_t5;
    struct1 _768_t2;
    int64_t _768_t1;
    int64_t _768_$retval;
    _768_t0 = _770_add;
    _768_t3 = 100;
    _768_t4 = 90;
    _768_t5 = 7;
    _768_t2 = (struct1) {_768_t3, _768_t4, _768_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _768_t1 = _768_t0(_768_t2);
    $line_idx--;
    _768_$retval = _768_t1;
    return _768_$retval;
}

int64_t _770_add(struct1 _770_x) {
    int64_t _770_t0;
    int64_t _770_t1;
    int64_t _770_t2;
    int64_t _770_t3;
    int64_t _770_$retval;
    _770_t0 = 0;
    _770_t1 = 1;
    _770_t2 = $add_int64_t(*((int64_t*)&_770_x + _770_t0), *((int64_t*)&_770_x + _770_t1), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _770_t3 = 2;
    _770_$retval = $add_int64_t(_770_t2, *((int64_t*)&_770_x + _770_t3), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _770_$retval;
}

int main(void) {
  printf("%ld",_768_main());
  return 0;
}
