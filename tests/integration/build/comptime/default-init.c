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
int64_t _110_add(int64_t _110_a,int64_t _110_b);
int64_t _108_main(void);

/* Function definitions */
int64_t _110_add(int64_t _110_a,int64_t _110_b) {
    int64_t _110_$retval;
    _110_$retval = $add_int64_t(_110_a, _110_b, "tests/integration/comptime/default-init.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _110_$retval;
}

int64_t _108_main(void) {
    int64_t _108_t1;
    int64_t _108_t2;
    struct0 _109_x;
    int64_t _108_$retval;
    _108_t1 = 240;
    _108_t2 = 5;
    _109_x = (struct0) {_108_t1, _108_t2};
    _108_$retval = $add_int64_t(_109_x._0, _109_x._1, "tests/integration/comptime/default-init.orng:4:10:\n    x.a + x.b\n        ^");
    return _108_$retval;
}

int main(void) {
  printf("%ld",_108_main());
  return 0;
}
