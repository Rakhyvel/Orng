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
int64_t _757_main(void);
int64_t _759_add(struct1 _759_x);

/* Function definitions */
int64_t _757_main(void) {
    function0 _757_t0;
    int64_t _757_t3;
    int64_t _757_t4;
    int64_t _757_t5;
    struct1 _757_t2;
    int64_t _757_t1;
    int64_t _757_$retval;
    _757_t0 = _759_add;
    _757_t3 = 100;
    _757_t4 = 90;
    _757_t5 = 7;
    _757_t2 = (struct1) {_757_t3, _757_t4, _757_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _757_t1 = _757_t0(_757_t2);
    $line_idx--;
    _757_$retval = _757_t1;
    return _757_$retval;
}

int64_t _759_add(struct1 _759_x) {
    int64_t _759_t0;
    int64_t _759_t1;
    int64_t _759_t2;
    int64_t _759_t3;
    int64_t _759_$retval;
    _759_t0 = 0;
    _759_t1 = 1;
    _759_t2 = $add_int64_t(*((int64_t*)&_759_x + _759_t0), *((int64_t*)&_759_x + _759_t1), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _759_t3 = 2;
    _759_$retval = $add_int64_t(_759_t2, *((int64_t*)&_759_x + _759_t3), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _759_$retval;
}

int main(void) {
  printf("%ld",_757_main());
  return 0;
}
