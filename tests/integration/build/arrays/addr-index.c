/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
} struct0;

/* Function forward definitions */
int64_t _12_main(void);

/* Function definitions */
int64_t _12_main(void){
    int64_t _12_t1;
    int64_t _12_t2;
    int64_t _12_t3;
    int64_t _12_t4;
    struct0 _13_x;
    int64_t _12_t5;
    int64_t _12_t6;
    int64_t* _13_y;
    int64_t _12_t9;
    int64_t _12_t10;
    int64_t _12_$retval;
    _12_t1 = 1;
    _12_t2 = 2;
    _12_t3 = 3;
    _12_t4 = 4;
    _13_x = (struct0) {_12_t1, _12_t2, _12_t3, _12_t4};
    _12_t5 = 0;
    _12_t6 = 4;
    $bounds_check(_12_t5, _12_t6, "tests/integration/arrays/addr-index.orng:4:24:\n    let y: &mut Int = &mut x[0]\n                      ^");
    _13_y = ((int64_t*)&_13_x + _12_t5);
    *_13_y = 63;
    _12_t9 = 0;
    _12_t10 = 4;
    $bounds_check(_12_t9, _12_t10, "tests/integration/arrays/addr-index.orng:2:3:\nfn main() -> Int {\n ^");
    _12_$retval = *((int64_t*)&_13_x + _12_t9);
    return _12_$retval;
}

int main(void) {
  printf("%ld",_12_main());
  return 0;
}
