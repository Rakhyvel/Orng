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
int64_t _75_add(int64_t _75_a,int64_t _75_b);
int64_t _71_main(void);

/* Function definitions */
int64_t _75_add(int64_t _75_a,int64_t _75_b){
    int64_t _75_$retval;
    _75_$retval = $add_int64_t(_75_a, _75_b, "tests/integration/comptime/index-heterotypical.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _75_$retval;
}

int64_t _71_main(void){
    uint32_t _71_t1;
    int64_t _71_t2;
    double _71_t3;
    struct0 _72_x;
    int64_t _71_$retval;
    _71_t1 = 960;
    _71_t2 = 248;
    _71_t3 = 3.14e+00;
    _72_x = (struct0) {_71_t1, _71_t2, _71_t3};
    _71_$retval = _72_x._1;
    return _71_$retval;
}

int main(void) {
  printf("%ld",_71_main());
  return 0;
}
