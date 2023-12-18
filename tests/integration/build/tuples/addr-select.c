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
int64_t _1714_main(void);

/* Function definitions */
int64_t _1714_main(void){
    int64_t _1714_t1;
    int64_t _1714_t2;
    int64_t _1714_t3;
    int64_t _1714_t4;
    struct0 _1715_x;
    int64_t* _1715_y;
    int64_t _1714_$retval;
    _1714_t1 = 1;
    _1714_t2 = 2;
    _1714_t3 = 3;
    _1714_t4 = 4;
    _1715_x = (struct0) {_1714_t1, _1714_t2, _1714_t3, _1714_t4};
    _1715_y = &_1715_x._3;
    *_1715_y = 66;
    _1714_$retval = _1715_x._3;
    return _1714_$retval;
}

int main(void) {
  printf("%ld",_1714_main());
  return 0;
}
