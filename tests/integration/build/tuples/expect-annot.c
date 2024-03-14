/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    struct struct0 _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _2_main(void);


/* Function definitions */
int64_t _2_main(void){
    int64_t _2_t2;
    int64_t _2_t3;
    struct struct0 _2_t1;
    int64_t _2_t4;
    struct struct1 _3_x;
    int64_t _2_$retval;
    _2_t2 = 4;
    _2_t3 = 4;
    _2_t1 = (struct struct0) {_2_t2, _2_t3};
    _2_t4 = 4;
    _3_x = (struct struct1) {_2_t1, _2_t4};
    _2_$retval = _3_x._1;
    return _2_$retval;
}


int main(void) {
  printf("%ld",_2_main());
  return 0;
}
