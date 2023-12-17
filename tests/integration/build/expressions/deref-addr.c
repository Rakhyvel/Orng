/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _756_main(void);

/* Function definitions */
int64_t _756_main(void){
    int64_t _757_x;
    int64_t* _756_t2;
    int64_t* _756_t3;
    int64_t _756_$retval;
    _757_x = 5;
    _756_t2 = &_757_x;
    *_756_t2 = 74;
    _756_t3 = &_757_x;
    _756_$retval = *_756_t3;
    return _756_$retval;
}

int main(void) {
  printf("%ld",_756_main());
  return 0;
}
