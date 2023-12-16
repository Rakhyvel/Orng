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
} struct0;

/* Function forward definitions */
int64_t _1514_main(void);

/* Function definitions */
int64_t _1514_main(void){
    int64_t _1514_t1;
    int64_t _1514_t2;
    struct0 _1515_x;
    struct0* _1514_t4;
    struct0* _1514_t5;
    int64_t _1514_$retval;
    _1514_t1 = 1;
    _1514_t2 = 2;
    _1515_x = (struct0) {_1514_t1, _1514_t2};
    _1514_t4 = &_1515_x;
    (*_1514_t4)._0 = 76;
    _1514_t5 = &_1515_x;
    _1514_$retval = (*_1514_t5)._0;
    return _1514_$retval;
}

int main(void) {
  printf("%ld",_1514_main());
  return 0;
}
