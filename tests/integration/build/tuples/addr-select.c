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
int64_t _1721_main(void);

/* Function definitions */
int64_t _1721_main(void){
    int64_t _1721_t1;
    int64_t _1721_t2;
    int64_t _1721_t3;
    int64_t _1721_t4;
    struct0 _1722_x;
    int64_t* _1722_y;
    int64_t _1721_$retval;
    _1721_t1 = 1;
    _1721_t2 = 2;
    _1721_t3 = 3;
    _1721_t4 = 4;
    _1722_x = (struct0) {_1721_t1, _1721_t2, _1721_t3, _1721_t4};
    _1722_y = &_1722_x._3;
    *_1722_y = 66;
    _1721_$retval = _1722_x._3;
    return _1721_$retval;
}

int main(void) {
  printf("%ld",_1721_main());
  return 0;
}
