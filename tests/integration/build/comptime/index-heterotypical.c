/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    uint32_t _0;
    int64_t _1;
    double _2;
};

/* Function forward definitions */
int64_t _233_add(int64_t _233_a, int64_t _233_b);
int64_t _230_main(void);


/* Function definitions */
int64_t _233_add(int64_t _233_a, int64_t _233_b){
    int64_t _233_$retval;
    _233_$retval = $add_int64_t(_233_a, _233_b, "tests/integration/comptime/index-heterotypical.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _233_$retval;
}

int64_t _230_main(void){
    uint32_t _230_t1;
    int64_t _230_t2;
    double _230_t3;
    struct struct0 _231_x;
    int64_t _230_$retval;
    _230_t1 = 960;
    _230_t2 = 248;
    _230_t3 = 3.14e+00;
    _231_x = (struct struct0) {_230_t1, _230_t2, _230_t3};
    _230_$retval = _231_x._1;
    return _230_$retval;
}


int main(void) {
  printf("%ld",_230_main());
  return 0;
}
