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
int64_t _1222_main(void);

/* Function definitions */
int64_t _1222_main(void) {
    int64_t _1222_t1;
    int64_t _1222_t2;
    struct0 _1223_x;
    struct0* _1222_t4;
    struct0* _1222_t5;
    int64_t _1222_$retval;
    _1222_t1 = 1;
    _1222_t2 = 2;
    _1223_x = (struct0) {_1222_t1, _1222_t2};
    _1222_t4 = &_1223_x;
    (*_1222_t4)._0 = 76;
    _1222_t5 = &_1223_x;
    _1222_$retval = (*_1222_t5)._0;
    return _1222_$retval;
}

int main(void) {
  printf("%ld",_1222_main());
  return 0;
}
