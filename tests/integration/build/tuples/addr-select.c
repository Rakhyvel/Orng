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
int64_t _1189_main(void);

/* Function definitions */
int64_t _1189_main(void) {
    int64_t _1189_t1;
    int64_t _1189_t2;
    int64_t _1189_t3;
    int64_t _1189_t4;
    struct0 _1190_x;
    int64_t* _1190_y;
    int64_t _1189_$retval;
    _1189_t1 = 1;
    _1189_t2 = 2;
    _1189_t3 = 3;
    _1189_t4 = 4;
    _1190_x = (struct0) {_1189_t1, _1189_t2, _1189_t3, _1189_t4};
    _1190_y = &_1190_x._3;
    *_1190_y = 66;
    _1189_$retval = _1190_x._3;
    return _1189_$retval;
}

int main(void) {
  printf("%ld",_1189_main());
  return 0;
}
