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
int64_t _1132_main(void);

/* Function definitions */
int64_t _1132_main(void) {
    int64_t _1132_t1;
    int64_t _1132_t2;
    int64_t _1132_t3;
    int64_t _1132_t4;
    struct0 _1133_x;
    int64_t* _1133_y;
    int64_t _1132_$retval;
    _1132_t1 = 1;
    _1132_t2 = 2;
    _1132_t3 = 3;
    _1132_t4 = 4;
    _1133_x = (struct0) {_1132_t1, _1132_t2, _1132_t3, _1132_t4};
    _1133_y = &_1133_x._3;
    *_1133_y = 66;
    _1132_$retval = _1133_x._3;
    return _1132_$retval;
}

int main(void) {
  printf("%ld",_1132_main());
  return 0;
}
