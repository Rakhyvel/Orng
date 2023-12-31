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
int64_t _130_add(int64_t _130_a, int64_t _130_b);
int64_t _122_main(void);

/* Function definitions */
int64_t _130_add(int64_t _130_a, int64_t _130_b){
    int64_t _130_$retval;
    _130_$retval = $add_int64_t(_130_a, _130_b, "tests/integration/comptime/default-init.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _130_$retval;
}

int64_t _122_main(void){
    int64_t _122_t1;
    int64_t _122_t2;
    struct struct0 _123_x;
    int64_t _122_$retval;
    _122_t1 = 240;
    _122_t2 = 5;
    _123_x = (struct struct0) {_122_t1, _122_t2};
    _122_$retval = $add_int64_t(_123_x._0, _123_x._1, "tests/integration/comptime/default-init.orng:4:10:\n    x.a + x.b\n        ^");
    return _122_$retval;
}

int main(void) {
  printf("%ld",_122_main());
  return 0;
}
