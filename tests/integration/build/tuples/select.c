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
int64_t _107_main(void);

/* Function definitions */
int64_t _107_main(void) {
    int64_t _107_t1;
    int64_t _107_t2;
    struct0 _108_x;
    int64_t _107_$retval;
    _107_t1 = 50;
    _107_t2 = 5;
    _108_x = (struct0) {_107_t1, _107_t2};
    _107_$retval = $add_int64_t(_108_x._0, _108_x._1, "tests/integration/tuples/select.orng:4:10:\n    x.a + x.b\n        ^");
    return _107_$retval;
}

int main(void) {
  printf("%ld",_107_main());
  return 0;
}
