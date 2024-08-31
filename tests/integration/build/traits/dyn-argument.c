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
int64_t _1557_main(void);
int64_t _1559_call_give_num(struct dyn2 _1559_x);
int64_t _1555_give_num(void);

/* Trait vtable implementations */
struct vtable_Give_Num _1554_$vtable = {
    .give_num = _1555_give_num,
};


/* Function definitions */
int64_t _1557_main(void){
    int64_t _1558_x;
    function1 _1557_t2;
    struct dyn2 _1557_t4;
    int64_t _1557_t3;
    int64_t _1557_$retval;
    _1558_x = 4;
    _1557_t2 = (function1) _1559_call_give_num;
    _1557_t4 = (struct dyn2) {&_1558_x, &_1554_$vtable};
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:15:19:\n    call_give_num(&x)\n                 ^";
    _1557_t3 = _1557_t2(_1557_t4);
    $line_idx--;
    _1557_$retval = _1557_t3;
    return _1557_$retval;
}

int64_t _1559_call_give_num(struct dyn2 _1559_x){
    int64_t _1559_t1;
    int64_t _1559_$retval;
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:20:8:\n    x.>give_num()\n      ^";
    _1559_t1 = _1559_x.vtable->give_num();
    $line_idx--;
    _1559_$retval = _1559_t1;
    return _1559_$retval;
}

int64_t _1555_give_num(void){
    int64_t _1555_$retval;
    _1555_$retval = 302;
    return _1555_$retval;
}


int main(void) {
  printf("%ld",_1557_main());
  return 0;
}
