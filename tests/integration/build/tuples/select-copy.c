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
int64_t _1174_main(void);

/* Function definitions */
int64_t _1174_main(void) {
    int64_t _1174_t1;
    int64_t _1174_t2;
    struct0 _1175_x;
    int64_t _1174_$retval;
    _1174_t1 = 50;
    _1174_t2 = 5;
    _1175_x = (struct0) {_1174_t1, _1174_t2};
    _1175_x._1 = 6;
    _1174_$retval = $add_int64_t(_1175_x._0, _1175_x._1, "tests/integration/tuples/select-copy.orng:5:10:\n    x.a + x.b\n        ^");
    return _1174_$retval;
}

int main(void) {
  printf("%ld",_1174_main());
  return 0;
}
