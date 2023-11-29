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
    int64_t _4;
} struct0;

/* Function forward definitions */
int64_t _111_main(void);

/* Function definitions */
int64_t _111_main(void) {
    int64_t _111_t1;
    int64_t _111_t2;
    int64_t _111_t3;
    int64_t _111_t4;
    int64_t _111_t5;
    struct0 _112_x;
    struct0* _112_y;
    int64_t _111_t7;
    int64_t _111_t8;
    int64_t _111_$retval;
    _111_t1 = 1;
    _111_t2 = 2;
    _111_t3 = 3;
    _111_t4 = 4;
    _111_t5 = 5;
    _112_x = (struct0) {_111_t1, _111_t2, _111_t3, _111_t4, _111_t5};
    _112_y = &_112_x;
    _111_t7 = 2;
    _111_t8 = 77;
    _111_$retval = $add_int64_t(*((int64_t*)_112_y + _111_t7), _111_t8, "tests/integration/arrays/implicit-deref.orng:5:11:\n    y[2] + 77\n         ^");
    return _111_$retval;
}

int main(void) {
  printf("%ld",_111_main());
  return 0;
}
