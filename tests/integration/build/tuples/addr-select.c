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
int64_t _1459_main(void);

/* Function definitions */
int64_t _1459_main(void){
    int64_t _1459_t1;
    int64_t _1459_t2;
    int64_t _1459_t3;
    int64_t _1459_t4;
    struct0 _1460_x;
    int64_t* _1460_y;
    int64_t _1459_$retval;
    _1459_t1 = 1;
    _1459_t2 = 2;
    _1459_t3 = 3;
    _1459_t4 = 4;
    _1460_x = (struct0) {_1459_t1, _1459_t2, _1459_t3, _1459_t4};
    _1460_y = &_1460_x._3;
    *_1460_y = 66;
    _1459_$retval = _1460_x._3;
    return _1459_$retval;
}

int main(void) {
  printf("%ld",_1459_main());
  return 0;
}
