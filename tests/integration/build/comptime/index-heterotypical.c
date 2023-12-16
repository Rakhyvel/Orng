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
int64_t _231_add(int64_t _231_a,int64_t _231_b);
int64_t _227_main(void);

/* Function definitions */
int64_t _231_add(int64_t _231_a,int64_t _231_b){
    int64_t _231_$retval;
    _231_$retval = $add_int64_t(_231_a, _231_b, "tests/integration/comptime/index-heterotypical.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _231_$retval;
}

int64_t _227_main(void){
    uint32_t _227_t1;
    int64_t _227_t2;
    double _227_t3;
    struct0 _228_x;
    int64_t _227_$retval;
    _227_t1 = 960;
    _227_t2 = 248;
    _227_t3 = 3.14e+00;
    _228_x = (struct0) {_227_t1, _227_t2, _227_t3};
    _227_$retval = _228_x._1;
    return _227_$retval;
}

int main(void) {
  printf("%ld",_227_main());
  return 0;
}
