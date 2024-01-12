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
int64_t _1505_main(void);

/* Function definitions */
int64_t _1505_main(void){
    int64_t _1505_t1;
    int64_t _1505_t2;
    int64_t _1505_t3;
    int64_t _1505_t4;
    struct struct0 _1506_x;
    int64_t* _1506_y;
    int64_t _1505_$retval;
    _1505_t1 = 1;
    _1505_t2 = 2;
    _1505_t3 = 3;
    _1505_t4 = 4;
    _1506_x = (struct struct0) {_1505_t1, _1505_t2, _1505_t3, _1505_t4};
    _1506_y = &_1506_x._3;
    *_1506_y = 66;
    _1505_$retval = _1506_x._3;
    return _1505_$retval;
}

int main(void) {
  printf("%ld",_1505_main());
  return 0;
}
