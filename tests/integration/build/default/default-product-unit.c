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
int64_t _460_main(void);

/* Function definitions */
int64_t _460_main(void){
    int64_t _460_t2;
    struct0 _461_x;
    struct0* _461_y;
    int64_t _460_t5;
    int64_t _460_$retval;
    _460_t2 = 0;
    _461_x = (struct0) {_460_t2, };
    _461_y = &_461_x;
    _460_t5 = 140;
    _460_$retval = $add_int64_t(_460_t5, (*_461_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _460_$retval;
}

int main(void) {
  printf("%ld",_460_main());
  return 0;
}
