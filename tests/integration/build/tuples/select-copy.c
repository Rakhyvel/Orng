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
int64_t _41_main(void);

/* Function definitions */
int64_t _41_main(void) {
    int64_t _41_t1;
    int64_t _41_t2;
    struct0 _42_x;
    int64_t _41_$retval;
    _41_t1 = 50;
    _41_t2 = 5;
    _42_x = (struct0) {_41_t1, _41_t2};
    _42_x._1 = 6;
    _41_$retval = $add_int64_t(_42_x._0, _42_x._1, "tests/integration/tuples/select-copy.orng:5:10:\n    x.a + x.b\n        ^");
    return _41_$retval;
}

int main(void) {
  printf("%ld",_41_main());
  return 0;
}
