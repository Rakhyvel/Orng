/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _377_main(void);

/* Function definitions */
int64_t _377_main(void) {
    int64_t _378_x;
    int64_t* _378_y;
    int64_t** _378_z;
    int64_t _377_$retval;
    _378_x = 75;
    _378_y = &_378_x;
    _378_z = &_378_y;
    **_378_z = 75;
    _377_$retval = **_378_z;
    return _377_$retval;
}

int main(void) {
  printf("%ld",_377_main());
  return 0;
}
