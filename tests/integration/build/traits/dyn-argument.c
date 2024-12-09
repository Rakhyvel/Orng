/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct dyn2;

/* Struct, union, and function definitions */
typedef int64_t(*function0)(void);

struct dyn2 {
    void* data_ptr;
    struct vtable_Give_Num* vtable;
};

typedef int64_t(*function1)(struct dyn2);

/* Trait vtable type definitions */
struct vtable_Give_Num {
    int64_t(*give_num)(void);
};

/* Function forward definitions */
int64_t _1660_main(void);
int64_t _1662_call_give_num(struct dyn2 _1662_x);
int64_t _1658_give_num(void);

/* Trait vtable implementations */
struct vtable_Give_Num _1657_$vtable = {
    .give_num = _1658_give_num,
};


/* Function definitions */
int64_t _1660_main(void){
    int64_t _1661_x;
    function1 _1660_t2;
    struct dyn2 _1660_t4;
    int64_t _1660_t3;
    int64_t _1660_$retval;
    _1661_x = 4;
    _1660_t2 = (function1) _1662_call_give_num;
    _1660_t4 = (struct dyn2) {&_1661_x, &_1657_$vtable};
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:15:19:\n    call_give_num(&x)\n                 ^";
    _1660_t3 = _1660_t2(_1660_t4);
    $line_idx--;
    _1660_$retval = _1660_t3;
    return _1660_$retval;
}

int64_t _1662_call_give_num(struct dyn2 _1662_x){
    int64_t _1662_t1;
    int64_t _1662_$retval;
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:20:8:\n    x.>give_num()\n      ^";
    _1662_t1 = _1662_x.vtable->give_num();
    $line_idx--;
    _1662_$retval = _1662_t1;
    return _1662_$retval;
}

int64_t _1658_give_num(void){
    int64_t _1658_$retval;
    _1658_$retval = 302;
    return _1658_$retval;
}


int main(void) {
  printf("%ld",_1660_main());
  return 0;
}
