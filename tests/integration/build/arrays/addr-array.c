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
int64_t _7_main(void);

/* Function definitions */
int64_t _7_main(void){
    int64_t _7_t1;
    int64_t _7_t2;
    int64_t _7_t3;
    int64_t _7_t4;
    struct0 _8_x;
    struct0* _8_y;
    int64_t _7_t7;
    int64_t _7_t8;
    int64_t _7_$retval;
    _7_t1 = 1;
    _7_t2 = 2;
    _7_t3 = 3;
    _7_t4 = 4;
    _8_x = (struct0) {_7_t1, _7_t2, _7_t3, _7_t4};
    _8_y = &_8_x;
    _7_t7 = 2;
    *((int64_t*)_8_y + _7_t7) = 70;
    _7_t8 = 2;
    _7_$retval = *((int64_t*)_8_y + _7_t8);
    return _7_$retval;
}

int main(void) {
  printf("%ld",_7_main());
  return 0;
}
