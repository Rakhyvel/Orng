/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    double _1;
};

/* Function forward definitions */
int64_t _566_main(void);


/* Function definitions */
int64_t _566_main(void){
    int64_t _566_t1;
    double _566_t2;
    struct struct0 _567_x;
    int64_t _566_$retval;
    _566_t1 = 137;
    _566_t2 = 0e0;
    _567_x = (struct struct0) {_566_t1, _566_t2};
    _566_$retval = _567_x._0;
    return _566_$retval;
}


int main(void) {
  printf("%ld",_566_main());
  return 0;
}
