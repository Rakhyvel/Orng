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
int64_t _531_main(void);

/* Function definitions */
int64_t _531_main(void){
    int64_t _531_t2;
    struct0 _532_x;
    struct0* _532_y;
    int64_t _531_t5;
    int64_t _531_$retval;
    _531_t2 = 0;
    _532_x = (struct0) {_531_t2, };
    _532_y = &_532_x;
    _531_t5 = 140;
    _531_$retval = $add_int64_t(_531_t5, (*_532_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _531_$retval;
}

int main(void) {
  printf("%ld",_531_main());
  return 0;
}
