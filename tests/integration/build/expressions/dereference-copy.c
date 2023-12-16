/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _685_main(void);

/* Function definitions */
int64_t _685_main(void){
    int64_t _686_x;
    int64_t* _686_y;
    int64_t _685_$retval;
    _686_x = 4;
    _686_y = &_686_x;
    *_686_y = 28;
    _685_$retval = *_686_y;
    return _685_$retval;
}

int main(void) {
  printf("%ld",_685_main());
  return 0;
}
