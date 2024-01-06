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
};

/* Function forward definitions */
int64_t _1536_main(void);

/* Function definitions */
int64_t _1536_main(void){
    int64_t _1536_t1;
    int64_t _1536_t2;
    struct struct0 _1537_x;
    struct struct0* _1536_t4;
    struct struct0* _1536_t5;
    int64_t _1536_$retval;
    _1536_t1 = 1;
    _1536_t2 = 2;
    _1537_x = (struct struct0) {_1536_t1, _1536_t2};
    _1536_t4 = &_1537_x;
    (*_1536_t4)._0 = 76;
    _1536_t5 = &_1537_x;
    _1536_$retval = (*_1536_t5)._0;
    return _1536_$retval;
}

int main(void) {
  printf("%ld",_1536_main());
  return 0;
}
