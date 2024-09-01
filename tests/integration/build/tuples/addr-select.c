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
int64_t _1773_main(void);


/* Function definitions */
int64_t _1773_main(void){
    int64_t _1773_t1;
    int64_t _1773_t2;
    int64_t _1773_t3;
    int64_t _1773_t4;
    struct struct0 _1774_x;
    int64_t* _1774_y;
    int64_t _1773_$retval;
    _1773_t1 = 1;
    _1773_t2 = 2;
    _1773_t3 = 3;
    _1773_t4 = 4;
    _1774_x = (struct struct0) {_1773_t1, _1773_t2, _1773_t3, _1773_t4};
    _1774_y = &_1774_x._3;
    *_1774_y = 66;
    _1773_$retval = _1774_x._3;
    return _1773_$retval;
}


int main(void) {
  printf("%ld",_1773_main());
  return 0;
}
