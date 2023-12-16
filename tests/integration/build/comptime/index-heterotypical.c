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
int64_t _217_add(int64_t _217_a,int64_t _217_b);
int64_t _213_main(void);

/* Function definitions */
int64_t _217_add(int64_t _217_a,int64_t _217_b){
    int64_t _217_$retval;
    _217_$retval = $add_int64_t(_217_a, _217_b, "tests/integration/comptime/index-heterotypical.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _217_$retval;
}

int64_t _213_main(void){
    uint32_t _213_t1;
    int64_t _213_t2;
    double _213_t3;
    struct0 _214_x;
    int64_t _213_$retval;
    _213_t1 = 960;
    _213_t2 = 248;
    _213_t3 = 3.14e+00;
    _214_x = (struct0) {_213_t1, _213_t2, _213_t3};
    _213_$retval = _214_x._1;
    return _213_$retval;
}

int main(void) {
  printf("%ld",_213_main());
  return 0;
}
