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
int64_t _1501_main(void);

/* Function definitions */
int64_t _1501_main(void){
    int64_t _1501_t1;
    int64_t _1501_t2;
    struct0 _1502_x;
    int64_t _1501_$retval;
    _1501_t1 = 50;
    _1501_t2 = 5;
    _1502_x = (struct0) {_1501_t1, _1501_t2};
    _1502_x._1 = 6;
    _1501_$retval = $add_int64_t(_1502_x._0, _1502_x._1, "tests/integration/tuples/select-copy.orng:5:10:\n    x.a + x.b\n        ^");
    return _1501_$retval;
}

int main(void) {
  printf("%ld",_1501_main());
  return 0;
}
