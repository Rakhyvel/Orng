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
int64_t _1462_main(void);

/* Function definitions */
int64_t _1462_main(void){
    int64_t _1462_t1;
    int64_t _1462_t2;
    int64_t _1462_t3;
    int64_t _1462_t4;
    struct0 _1463_x;
    int64_t* _1463_y;
    int64_t _1462_$retval;
    _1462_t1 = 1;
    _1462_t2 = 2;
    _1462_t3 = 3;
    _1462_t4 = 4;
    _1463_x = (struct0) {_1462_t1, _1462_t2, _1462_t3, _1462_t4};
    _1463_y = &_1463_x._3;
    *_1463_y = 66;
    _1462_$retval = _1463_x._3;
    return _1462_$retval;
}

int main(void) {
  printf("%ld",_1462_main());
  return 0;
}
