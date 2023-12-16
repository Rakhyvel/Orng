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
    int64_t _3;
} struct0;

/* Function forward definitions */
int64_t _1470_main(void);

/* Function definitions */
int64_t _1470_main(void){
    int64_t _1470_t1;
    int64_t _1470_t2;
    int64_t _1470_t3;
    int64_t _1470_t4;
    struct0 _1471_x;
    int64_t* _1471_y;
    int64_t _1470_$retval;
    _1470_t1 = 1;
    _1470_t2 = 2;
    _1470_t3 = 3;
    _1470_t4 = 4;
    _1471_x = (struct0) {_1470_t1, _1470_t2, _1470_t3, _1470_t4};
    _1471_y = &_1471_x._3;
    *_1471_y = 66;
    _1470_$retval = _1471_x._3;
    return _1470_$retval;
}

int main(void) {
  printf("%ld",_1470_main());
  return 0;
}
