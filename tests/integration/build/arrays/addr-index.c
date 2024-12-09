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
int64_t _13_main(void);


/* Function definitions */
int64_t _13_main(void){
    int64_t _13_t1;
    int64_t _13_t2;
    int64_t _13_t3;
    int64_t _13_t4;
    struct struct0 _14_x;
    int64_t _13_t6;
    int64_t _13_t7;
    int64_t* _14_y;
    int64_t _13_t11;
    int64_t _13_t12;
    int64_t _13_$retval;
    _13_t1 = 1;
    _13_t2 = 2;
    _13_t3 = 3;
    _13_t4 = 4;
    _14_x = (struct struct0) {_13_t1, _13_t2, _13_t3, _13_t4};
    _13_t6 = 0;
    _13_t7 = 4;
    $bounds_check(_13_t6, _13_t7, "tests/integration/arrays/addr-index.orng:4:24:\n    let y: &mut Int = &mut x[0]\n                      ^");
    _14_y = ((int64_t*)&_14_x + _13_t6);
    *_14_y = 63;
    _13_t11 = 0;
    _13_t12 = 4;
    $bounds_check(_13_t11, _13_t12, "tests/integration/arrays/addr-index.orng:2:8:\nfn main() -> Int {\n      ^");
    _13_$retval = *((int64_t*)&_14_x + _13_t11);
    return _13_$retval;
}


int main(void) {
  printf("%ld",_13_main());
  return 0;
}
