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
int64_t _81_main(void);

/* Function definitions */
int64_t _81_main(void) {
    int64_t _81_t1;
    int64_t _81_t2;
    int64_t _81_t3;
    int64_t _81_t4;
    int64_t _81_t5;
    struct0 _82_x;
    struct0* _82_y;
    int64_t _81_t7;
    int64_t _81_t8;
    int64_t _81_$retval;
    _81_t1 = 1;
    _81_t2 = 2;
    _81_t3 = 3;
    _81_t4 = 4;
    _81_t5 = 5;
    _82_x = (struct0) {_81_t1, _81_t2, _81_t3, _81_t4, _81_t5};
    _82_y = &_82_x;
    _81_t7 = 2;
    _81_t8 = 77;
    _81_$retval = $add_int64_t(*((int64_t*)_82_y + _81_t7), _81_t8, "tests/integration/arrays/implicit-deref.orng:5:11:\n    y[2] + 77\n         ^");
    return _81_$retval;
}

int main(void) {
  printf("%ld",_81_main());
  return 0;
}
