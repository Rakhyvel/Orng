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
int64_t _1508_main(void);

/* Function definitions */
int64_t _1508_main(void){
    int64_t _1508_t1;
    int64_t _1508_t2;
    struct0 _1509_x;
    int64_t _1508_$retval;
    _1508_t1 = 50;
    _1508_t2 = 5;
    _1509_x = (struct0) {_1508_t1, _1508_t2};
    _1508_$retval = $add_int64_t(_1509_x._0, _1509_x._1, "tests/integration/tuples/select.orng:4:10:\n    x.a + x.b\n        ^");
    return _1508_$retval;
}

int main(void) {
  printf("%ld",_1508_main());
  return 0;
}
