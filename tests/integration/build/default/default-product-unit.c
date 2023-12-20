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
int64_t _528_main(void);

/* Function definitions */
int64_t _528_main(void){
    int64_t _528_t2;
    struct0 _529_x;
    struct0* _529_y;
    int64_t _528_t5;
    int64_t _528_$retval;
    _528_t2 = 0;
    _529_x = (struct0) {_528_t2, };
    _529_y = &_529_x;
    _528_t5 = 140;
    _528_$retval = $add_int64_t(_528_t5, (*_529_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _528_$retval;
}

int main(void) {
  printf("%ld",_528_main());
  return 0;
}
