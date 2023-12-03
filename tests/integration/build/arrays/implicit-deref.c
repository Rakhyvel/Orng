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
int64_t _63_main(void);

/* Function definitions */
int64_t _63_main(void) {
    int64_t _63_t1;
    int64_t _63_t2;
    int64_t _63_t3;
    int64_t _63_t4;
    int64_t _63_t5;
    struct0 _64_x;
    struct0* _64_y;
    int64_t _63_t7;
    int64_t _63_t8;
    int64_t _63_$retval;
    _63_t1 = 1;
    _63_t2 = 2;
    _63_t3 = 3;
    _63_t4 = 4;
    _63_t5 = 5;
    _64_x = (struct0) {_63_t1, _63_t2, _63_t3, _63_t4, _63_t5};
    _64_y = &_64_x;
    _63_t7 = 2;
    _63_t8 = 77;
    _63_$retval = $add_int64_t(*((int64_t*)_64_y + _63_t7), _63_t8, "tests/integration/arrays/implicit-deref.orng:5:11:\n    y[2] + 77\n         ^");
    return _63_$retval;
}

int main(void) {
  printf("%ld",_63_main());
  return 0;
}
