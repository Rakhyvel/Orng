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
int64_t _1017_main(void);
int64_t _1019_add(struct1 _1019_x);

/* Function definitions */
int64_t _1017_main(void){
    function0 _1017_t0;
    int64_t _1017_t3;
    int64_t _1017_t4;
    int64_t _1017_t5;
    struct1 _1017_t2;
    int64_t _1017_t1;
    int64_t _1017_$retval;
    _1017_t0 = _1019_add;
    _1017_t3 = 100;
    _1017_t4 = 90;
    _1017_t5 = 7;
    _1017_t2 = (struct1) {_1017_t3, _1017_t4, _1017_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _1017_t1 = _1017_t0(_1017_t2);
    $line_idx--;
    _1017_$retval = _1017_t1;
    return _1017_$retval;
}

int64_t _1019_add(struct1 _1019_x){
    int64_t _1019_t0;
    int64_t _1019_t1;
    int64_t _1019_t2;
    int64_t _1019_t3;
    int64_t _1019_$retval;
    _1019_t0 = 0;
    _1019_t1 = 1;
    _1019_t2 = $add_int64_t(*((int64_t*)&_1019_x + _1019_t0), *((int64_t*)&_1019_x + _1019_t1), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _1019_t3 = 2;
    _1019_$retval = $add_int64_t(_1019_t2, *((int64_t*)&_1019_x + _1019_t3), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _1019_$retval;
}

int main(void) {
  printf("%ld",_1017_main());
  return 0;
}
