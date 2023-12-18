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
int64_t _1723_main(void);

/* Function definitions */
int64_t _1723_main(void){
    int64_t _1723_t1;
    int64_t _1723_t2;
    struct0 _1724_x;
    int64_t _1723_$retval;
    _1723_t1 = 50;
    _1723_t2 = 7;
    _1724_x = (struct0) {_1723_t1, _1723_t2};
    _1723_$retval = $add_int64_t(_1724_x._0, _1724_x._1, "tests/integration/tuples/default-fields.orng:4:10:\n    x.a + x.b\n        ^");
    return _1723_$retval;
}

int main(void) {
  printf("%ld",_1723_main());
  return 0;
}
