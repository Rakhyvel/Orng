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
int64_t _957_main(void);
int64_t _959_add(struct1 _959_x);

/* Function definitions */
int64_t _957_main(void){
    function0 _957_t0;
    int64_t _957_t3;
    int64_t _957_t4;
    int64_t _957_t5;
    struct1 _957_t2;
    int64_t _957_t1;
    int64_t _957_$retval;
    _957_t0 = _959_add;
    _957_t3 = 100;
    _957_t4 = 90;
    _957_t5 = 7;
    _957_t2 = (struct1) {_957_t3, _957_t4, _957_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _957_t1 = _957_t0(_957_t2);
    $line_idx--;
    _957_$retval = _957_t1;
    return _957_$retval;
}

int64_t _959_add(struct1 _959_x){
    int64_t _959_t0;
    int64_t _959_t1;
    int64_t _959_t2;
    int64_t _959_t3;
    int64_t _959_$retval;
    _959_t0 = 0;
    _959_t1 = 1;
    _959_t2 = $add_int64_t(*((int64_t*)&_959_x + _959_t0), *((int64_t*)&_959_x + _959_t1), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _959_t3 = 2;
    _959_$retval = $add_int64_t(_959_t2, *((int64_t*)&_959_x + _959_t3), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _959_$retval;
}

int main(void) {
  printf("%ld",_957_main());
  return 0;
}
