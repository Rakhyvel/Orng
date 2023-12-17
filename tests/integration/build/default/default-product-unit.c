/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _616_main(void);

/* Function definitions */
int64_t _616_main(void){
    int64_t _616_t2;
    struct0 _617_x;
    struct0* _617_y;
    int64_t _616_t5;
    int64_t _616_$retval;
    _616_t2 = 0;
    _617_x = (struct0) {_616_t2, };
    _617_y = &_617_x;
    _616_t5 = 140;
    _616_$retval = $add_int64_t(_616_t5, (*_617_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _616_$retval;
}

int main(void) {
  printf("%ld",_616_main());
  return 0;
}
