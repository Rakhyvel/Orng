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
int64_t _47_add(int64_t _47_a,int64_t _47_b);
int64_t _39_main(void);

/* Function definitions */
int64_t _47_add(int64_t _47_a,int64_t _47_b) {
    int64_t _47_$retval;
    _47_$retval = $add_int64_t(_47_a, _47_b, "tests/integration/comptime/default.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _47_$retval;
}

int64_t _39_main(void) {
    int64_t _39_t1;
    int64_t _39_t2;
    struct0 _40_x;
    int64_t _39_$retval;
    _39_t1 = 240;
    _39_t2 = 5;
    _40_x = (struct0) {_39_t1, _39_t2};
    _39_$retval = $add_int64_t(_40_x._0, _40_x._1, "tests/integration/comptime/default.orng:4:10:\n    x.a + x.b\n        ^");
    return _39_$retval;
}

int main(void) {
  printf("%ld",_39_main());
  return 0;
}
