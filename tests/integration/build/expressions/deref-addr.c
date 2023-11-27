/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _369_main(void);

/* Function definitions */
int64_t _369_main(void) {
    int64_t _370_x;
    int64_t* _369_t2;
    int64_t* _369_t3;
    int64_t _369_$retval;
    _370_x = 5;
    _369_t2 = &_370_x;
    *_369_t2 = 74;
    _369_t3 = &_370_x;
    _369_$retval = *_369_t3;
    return _369_$retval;
}

int main(void) {
  printf("%ld",_369_main());
  return 0;
}
