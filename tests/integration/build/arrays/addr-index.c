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
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

/* Function forward definitions */
int64_t _17_main(void);


/* Function definitions */
int64_t _17_main(void){
    int64_t _17_t1;
    int64_t _17_t2;
    int64_t _17_t3;
    int64_t _17_t4;
    struct struct0 _18_x;
    int64_t _17_t6;
    int64_t _17_t7;
    int64_t* _18_y;
    int64_t _17_t11;
    int64_t _17_t12;
    int64_t _17_$retval;
    _17_t1 = 1;
    _17_t2 = 2;
    _17_t3 = 3;
    _17_t4 = 4;
    _18_x = (struct struct0) {_17_t1, _17_t2, _17_t3, _17_t4};
    _17_t6 = 0;
    _17_t7 = 4;
    $bounds_check(_17_t6, _17_t7, "tests/integration/arrays/addr-index.orng:4:24:\n    let y: &mut Int = &mut x[0]\n                      ^");
    _18_y = ((int64_t*)&_18_x + _17_t6);
    *_18_y = 63;
    _17_t11 = 0;
    _17_t12 = 4;
    $bounds_check(_17_t11, _17_t12, "tests/integration/arrays/addr-index.orng:2:8:\nfn main() -> Int {\n      ^");
    _17_$retval = *((int64_t*)&_18_x + _17_t11);
    return _17_$retval;
}


int main(void) {
  printf("%ld",_17_main());
  return 0;
}
