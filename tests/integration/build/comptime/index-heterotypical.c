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
int64_t _316_add(int64_t _316_a,int64_t _316_b);
int64_t _312_main(void);

/* Function definitions */
int64_t _316_add(int64_t _316_a,int64_t _316_b){
    int64_t _316_$retval;
    _316_$retval = $add_int64_t(_316_a, _316_b, "tests/integration/comptime/index-heterotypical.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _316_$retval;
}

int64_t _312_main(void){
    uint32_t _312_t1;
    int64_t _312_t2;
    double _312_t3;
    struct0 _313_x;
    int64_t _312_$retval;
    _312_t1 = 960;
    _312_t2 = 248;
    _312_t3 = 3.14e+00;
    _313_x = (struct0) {_312_t1, _312_t2, _312_t3};
    _312_$retval = _313_x._1;
    return _312_$retval;
}

int main(void) {
  printf("%ld",_312_main());
  return 0;
}
