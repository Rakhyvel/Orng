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
int64_t _29_add(int64_t _29_a,int64_t _29_b);
int64_t _25_main(void);

/* Function definitions */
int64_t _29_add(int64_t _29_a,int64_t _29_b) {
    int64_t _29_$retval;
    _29_$retval = $add_int64_t(_29_a, _29_b, "tests/integration/comptime/default.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _29_$retval;
}

int64_t _25_main(void) {
    int64_t _25_t1;
    int64_t _25_t2;
    struct0 _26_x;
    int64_t _25_$retval;
    _25_t1 = 240;
    _25_t2 = 5;
    _26_x = (struct0) {_25_t1, _25_t2};
    _25_$retval = $add_int64_t(_26_x._0, _26_x._1, "tests/integration/comptime/default.orng:4:10:\n    x.a + x.b\n        ^");
    return _25_$retval;
}

int main(void) {
  printf("%ld",_25_main());
  return 0;
}
