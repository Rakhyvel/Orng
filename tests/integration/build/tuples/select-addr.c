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
} struct0;

/* Function forward definitions */
int64_t _38_main(void);

/* Function definitions */
int64_t _38_main(void) {
    int64_t _38_t1;
    int64_t _38_t2;
    struct0 _39_x;
    struct0* _38_t4;
    struct0* _38_t5;
    int64_t _38_$retval;
    _38_t1 = 1;
    _38_t2 = 2;
    _39_x = (struct0) {_38_t1, _38_t2};
    _38_t4 = &_39_x;
    (*_38_t4)._0 = 76;
    _38_t5 = &_39_x;
    _38_$retval = (*_38_t5)._0;
    return _38_$retval;
}

int main(void) {
  printf("%ld",_38_main());
  return 0;
}
