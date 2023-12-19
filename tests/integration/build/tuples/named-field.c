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
int64_t _1767_main(void);

/* Function definitions */
int64_t _1767_main(void){
    int64_t _1767_t1;
    int64_t _1767_t2;
    struct0 _1768_x;
    int64_t _1767_$retval;
    _1767_t1 = 20;
    _1767_t2 = 3;
    _1768_x = (struct0) {_1767_t1, _1767_t2};
    _1767_$retval = $mult_int64_t(_1768_x._0, _1768_x._1, "tests/integration/tuples/named-field.orng:4:10:\n    x.a * x.b\n        ^");
    return _1767_$retval;
}

int main(void) {
  printf("%ld",_1767_main());
  return 0;
}
