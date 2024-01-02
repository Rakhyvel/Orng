/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

/* Function forward definitions */
int64_t _1490_main(void);

/* Function definitions */
int64_t _1490_main(void){
    int64_t _1490_t1;
    int64_t _1490_t2;
    int64_t _1490_t3;
    int64_t _1490_t4;
    struct struct0 _1491_x;
    int64_t* _1491_y;
    int64_t _1490_$retval;
    _1490_t1 = 1;
    _1490_t2 = 2;
    _1490_t3 = 3;
    _1490_t4 = 4;
    _1491_x = (struct struct0) {_1490_t1, _1490_t2, _1490_t3, _1490_t4};
    _1491_y = &_1491_x._3;
    *_1491_y = 66;
    _1490_$retval = _1491_x._3;
    return _1490_$retval;
}

int main(void) {
  printf("%ld",_1490_main());
  return 0;
}
