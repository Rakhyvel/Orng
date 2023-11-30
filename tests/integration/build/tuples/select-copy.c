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
int64_t _90_main(void);

/* Function definitions */
int64_t _90_main(void) {
    int64_t _90_t1;
    int64_t _90_t2;
    struct0 _91_x;
    int64_t _90_$retval;
    _90_t1 = 50;
    _90_t2 = 5;
    _91_x = (struct0) {_90_t1, _90_t2};
    _91_x._1 = 6;
    _90_$retval = $add_int64_t(_91_x._0, _91_x._1, "tests/integration/tuples/select-copy.orng:5:10:\n    x.a + x.b\n        ^");
    return _90_$retval;
}

int main(void) {
  printf("%ld",_90_main());
  return 0;
}
