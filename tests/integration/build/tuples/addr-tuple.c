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
} struct0;

/* Function forward definitions */
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _2_x;
    struct0* _2_y;
    int64_t _1_$retval;
    _2_x = (struct0) {19, 39};
    _2_y = &_2_x;
    _1_$retval = $add_int64_t(_2_y->_0, _2_y->_1, "tests/integration/tuples/addr-tuple.orng:2:3:\nfn main() -> Int {\n ^");
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
