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
    int64_t _2;
};

/* Function forward definitions */
int64_t _1156_main(void);

/* Function definitions */
int64_t _1156_main(void){
    int64_t _1156_t1;
    int64_t _1156_t2;
    int64_t _1156_t3;
    struct struct0 _1156_t0;
    int64_t _1157_a;
    int64_t _1157_c;
    int64_t _1156_$retval;
    _1156_t1 = 100;
    _1156_t2 = 300;
    _1156_t3 = 56;
    _1156_t0 = (struct struct0) {_1156_t1, _1156_t2, _1156_t3};
    _1157_a = _1156_t0._0;
    _1157_c = _1156_t0._2;
    _1156_$retval = $add_int64_t(_1157_a, _1157_c, "tests/integration/pattern/let-ignore-product.orng:4:8:\n    a + c\n      ^");
    return _1156_$retval;
}

int main(void) {
  printf("%ld",_1156_main());
  return 0;
}
