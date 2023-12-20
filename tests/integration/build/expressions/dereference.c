/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _658_main(void);

/* Function definitions */
int64_t _658_main(void){
    int64_t _659_x;
    int64_t* _659_y;
    int64_t _658_$retval;
    _659_x = 29;
    _659_y = &_659_x;
    _658_$retval = *_659_y;
    return _658_$retval;
}

int main(void) {
  printf("%ld",_658_main());
  return 0;
}
