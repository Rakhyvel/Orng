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
int64_t _1615_main(void);

/* Function definitions */
int64_t _1615_main(void){
    int64_t _1615_t1;
    int64_t _1615_t2;
    int64_t _1615_t3;
    int64_t _1615_t4;
    struct0 _1616_x;
    int64_t* _1616_y;
    int64_t _1615_$retval;
    _1615_t1 = 1;
    _1615_t2 = 2;
    _1615_t3 = 3;
    _1615_t4 = 4;
    _1616_x = (struct0) {_1615_t1, _1615_t2, _1615_t3, _1615_t4};
    _1616_y = &_1616_x._3;
    *_1616_y = 66;
    _1615_$retval = _1616_x._3;
    return _1615_$retval;
}

int main(void) {
  printf("%ld",_1615_main());
  return 0;
}
