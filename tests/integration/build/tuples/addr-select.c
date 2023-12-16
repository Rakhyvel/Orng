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
int64_t _1451_main(void);

/* Function definitions */
int64_t _1451_main(void) {
    int64_t _1451_t1;
    int64_t _1451_t2;
    int64_t _1451_t3;
    int64_t _1451_t4;
    struct0 _1452_x;
    int64_t* _1452_y;
    int64_t _1451_$retval;
    _1451_t1 = 1;
    _1451_t2 = 2;
    _1451_t3 = 3;
    _1451_t4 = 4;
    _1452_x = (struct0) {_1451_t1, _1451_t2, _1451_t3, _1451_t4};
    _1452_y = &_1452_x._3;
    *_1452_y = 66;
    _1451_$retval = _1452_x._3;
    return _1451_$retval;
}

int main(void) {
  printf("%ld",_1451_main());
  return 0;
}
