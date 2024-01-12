/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1549_main(void);

/* Function definitions */
int64_t _1549_main(void){
    int64_t _1549_t1;
    int64_t _1549_t2;
    struct struct0 _1550_x;
    int64_t _1549_$retval;
    _1549_t1 = 50;
    _1549_t2 = 5;
    _1550_x = (struct struct0) {_1549_t1, _1549_t2};
    _1550_x._1 = 6;
    _1549_$retval = $add_int64_t(_1550_x._0, _1550_x._1, "tests/integration/tuples/select-copy.orng:5:10:\n    x.a + x.b\n        ^");
    return _1549_$retval;
}

int main(void) {
  printf("%ld",_1549_main());
  return 0;
}
