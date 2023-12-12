/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint32_t _0;
    int64_t _1;
    double _2;
} struct0;

/* Function forward definitions */
int64_t _36_add(int64_t _36_a,int64_t _36_b);
int64_t _34_main(void);

/* Function definitions */
int64_t _36_add(int64_t _36_a,int64_t _36_b) {
    int64_t _36_$retval;
    _36_$retval = $add_int64_t(_36_a, _36_b, "tests/integration/comptime/index-heterotypical.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _36_$retval;
}

int64_t _34_main(void) {
    uint32_t _34_t1;
    int64_t _34_t2;
    double _34_t3;
    struct0 _35_x;
    int64_t _34_$retval;
    _34_t1 = 960;
    _34_t2 = 248;
    _34_t3 = 3.14e+00;
    _35_x = (struct0) {_34_t1, _34_t2, _34_t3};
    _34_$retval = _35_x._1;
    return _34_$retval;
}

int main(void) {
  printf("%ld",_34_main());
  return 0;
}
