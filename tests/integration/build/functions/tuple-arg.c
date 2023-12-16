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
int64_t _946_main(void);
int64_t _948_add(struct1 _948_x);

/* Function definitions */
int64_t _946_main(void){
    function0 _946_t0;
    int64_t _946_t3;
    int64_t _946_t4;
    int64_t _946_t5;
    struct1 _946_t2;
    int64_t _946_t1;
    int64_t _946_$retval;
    _946_t0 = _948_add;
    _946_t3 = 100;
    _946_t4 = 90;
    _946_t5 = 7;
    _946_t2 = (struct1) {_946_t3, _946_t4, _946_t5};
    $lines[$line_idx++] = "tests/integration/functions/tuple-arg.orng:3:9:\n    add((100, 90, 7))\n       ^";
    _946_t1 = _946_t0(_946_t2);
    $line_idx--;
    _946_$retval = _946_t1;
    return _946_$retval;
}

int64_t _948_add(struct1 _948_x){
    int64_t _948_t0;
    int64_t _948_t1;
    int64_t _948_t2;
    int64_t _948_t3;
    int64_t _948_$retval;
    _948_t0 = 0;
    _948_t1 = 1;
    _948_t2 = $add_int64_t(*((int64_t*)&_948_x + _948_t0), *((int64_t*)&_948_x + _948_t1), "tests/integration/functions/tuple-arg.orng:7:11:\n    x[0] + x[1] + x[2]\n         ^");
    _948_t3 = 2;
    _948_$retval = $add_int64_t(_948_t2, *((int64_t*)&_948_x + _948_t3), "tests/integration/functions/tuple-arg.orng:7:18:\n    x[0] + x[1] + x[2]\n                ^");
    return _948_$retval;
}

int main(void) {
  printf("%ld",_946_main());
  return 0;
}
