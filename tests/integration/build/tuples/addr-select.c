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
int64_t _1704_main(void);

/* Function definitions */
int64_t _1704_main(void){
    int64_t _1704_t1;
    int64_t _1704_t2;
    int64_t _1704_t3;
    int64_t _1704_t4;
    struct0 _1705_x;
    int64_t* _1705_y;
    int64_t _1704_$retval;
    _1704_t1 = 1;
    _1704_t2 = 2;
    _1704_t3 = 3;
    _1704_t4 = 4;
    _1705_x = (struct0) {_1704_t1, _1704_t2, _1704_t3, _1704_t4};
    _1705_y = &_1705_x._3;
    *_1705_y = 66;
    _1704_$retval = _1705_x._3;
    return _1704_$retval;
}

int main(void) {
  printf("%ld",_1704_main());
  return 0;
}
