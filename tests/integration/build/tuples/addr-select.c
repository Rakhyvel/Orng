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
int64_t _1487_main(void);

/* Function definitions */
int64_t _1487_main(void){
    int64_t _1487_t1;
    int64_t _1487_t2;
    int64_t _1487_t3;
    int64_t _1487_t4;
    struct struct0 _1488_x;
    int64_t* _1488_y;
    int64_t _1487_$retval;
    _1487_t1 = 1;
    _1487_t2 = 2;
    _1487_t3 = 3;
    _1487_t4 = 4;
    _1488_x = (struct struct0) {_1487_t1, _1487_t2, _1487_t3, _1487_t4};
    _1488_y = &_1488_x._3;
    *_1488_y = 66;
    _1487_$retval = _1488_x._3;
    return _1487_$retval;
}

int main(void) {
  printf("%ld",_1487_main());
  return 0;
}
