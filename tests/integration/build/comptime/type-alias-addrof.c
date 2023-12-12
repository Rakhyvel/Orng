/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _81_main(void);

/* Function definitions */
int64_t _81_main(void) {
    int64_t _82_x;
    int64_t* _82_y;
    int64_t _81_$retval;
    _82_x = 242;
    _82_y = &_82_x;
    _81_$retval = *_82_y;
    return _81_$retval;
}

int main(void) {
  printf("%ld",_81_main());
  return 0;
}
