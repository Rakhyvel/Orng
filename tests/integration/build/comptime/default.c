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
int64_t _197_add(int64_t _197_a,int64_t _197_b);
int64_t _190_main(void);

/* Function definitions */
int64_t _197_add(int64_t _197_a,int64_t _197_b) {
    int64_t _197_$retval;
    _197_$retval = $add_int64_t(_197_a, _197_b, "tests/integration/comptime/default.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _197_$retval;
}

int64_t _190_main(void) {
    int64_t _190_t1;
    int64_t _190_t2;
    struct0 _191_x;
    int64_t _190_$retval;
    _190_t1 = 240;
    _190_t2 = 5;
    _191_x = (struct0) {_190_t1, _190_t2};
    _190_$retval = $add_int64_t(_191_x._0, _191_x._1, "tests/integration/comptime/default.orng:4:10:\n    x.a + x.b\n        ^");
    return _190_$retval;
}

int main(void) {
  printf("%ld",_190_main());
  return 0;
}
