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
int64_t _35_add(int64_t _35_a,int64_t _35_b);
int64_t _31_main(void);

/* Function definitions */
int64_t _35_add(int64_t _35_a,int64_t _35_b) {
    int64_t _35_$retval;
    _35_$retval = $add_int64_t(_35_a, _35_b, "tests/integration/comptime/default.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _35_$retval;
}

int64_t _31_main(void) {
    int64_t _31_t1;
    int64_t _31_t2;
    struct0 _32_x;
    int64_t _31_$retval;
    _31_t1 = 240;
    _31_t2 = 5;
    _32_x = (struct0) {_31_t1, _31_t2};
    _31_$retval = $add_int64_t(_32_x._0, _32_x._1, "tests/integration/comptime/default.orng:4:10:\n    x.a + x.b\n        ^");
    return _31_$retval;
}

int main(void) {
  printf("%ld",_31_main());
  return 0;
}
