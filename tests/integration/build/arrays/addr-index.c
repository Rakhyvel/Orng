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
int64_t _8_main(void);


/* Function definitions */
int64_t _8_main(void){
    int64_t _8_t1;
    int64_t _8_t2;
    int64_t _8_t3;
    int64_t _8_t4;
    struct struct0 _9_x;
    int64_t _8_t6;
    int64_t _8_t7;
    int64_t* _9_y;
    int64_t _8_t11;
    int64_t _8_t12;
    int64_t _8_$retval;
    _8_t1 = 1;
    _8_t2 = 2;
    _8_t3 = 3;
    _8_t4 = 4;
    _9_x = (struct struct0) {_8_t1, _8_t2, _8_t3, _8_t4};
    _8_t6 = 0;
    _8_t7 = 4;
    $bounds_check(_8_t6, _8_t7, "tests/integration/arrays/addr-index.orng:4:24:\n    let y: &mut Int = &mut x[0]\n                      ^");
    _9_y = ((int64_t*)&_9_x + _8_t6);
    *_9_y = 63;
    _8_t11 = 0;
    _8_t12 = 4;
    $bounds_check(_8_t11, _8_t12, "tests/integration/arrays/addr-index.orng:2:8:\nfn main() -> Int {\n      ^");
    _8_$retval = *((int64_t*)&_9_x + _8_t11);
    return _8_$retval;
}


int main(void) {
  printf("%ld",_8_main());
  return 0;
}
