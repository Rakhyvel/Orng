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
    struct struct0 _1;
};

/* Function forward definitions */
int64_t _1821_main(void);


/* Function definitions */
int64_t _1821_main(void){
    int64_t _1821_t2;
    int64_t _1821_t3;
    struct struct0 _1821_t1;
    int64_t _1821_t5;
    int64_t _1821_t6;
    struct struct0 _1821_t4;
    struct struct1 _1822_x;
    int64_t _1821_$retval;
    _1821_t2 = 1;
    _1821_t3 = 2;
    _1821_t1 = (struct struct0) {_1821_t2, _1821_t3};
    _1821_t5 = 3;
    _1821_t6 = 4;
    _1821_t4 = (struct struct0) {_1821_t5, _1821_t6};
    _1822_x = (struct struct1) {_1821_t1, _1821_t4};
    _1822_x._0._0 = 77;
    _1821_$retval = _1822_x._0._0;
    return _1821_$retval;
}


int main(void) {
  printf("%ld",_1821_main());
  return 0;
}
