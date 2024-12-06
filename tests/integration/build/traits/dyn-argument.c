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
int64_t _1647_main(void);
int64_t _1649_call_give_num(struct dyn2 _1649_x);
int64_t _1645_give_num(void);

/* Trait vtable implementations */
struct vtable_Give_Num _1644_$vtable = {
    .give_num = _1645_give_num,
};


/* Function definitions */
int64_t _1647_main(void){
    int64_t _1648_x;
    function1 _1647_t2;
    struct dyn2 _1647_t4;
    int64_t _1647_t3;
    int64_t _1647_$retval;
    _1648_x = 4;
    _1647_t2 = (function1) _1649_call_give_num;
    _1647_t4 = (struct dyn2) {&_1648_x, &_1644_$vtable};
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:15:19:\n    call_give_num(&x)\n                 ^";
    _1647_t3 = _1647_t2(_1647_t4);
    $line_idx--;
    _1647_$retval = _1647_t3;
    return _1647_$retval;
}

int64_t _1649_call_give_num(struct dyn2 _1649_x){
    int64_t _1649_t1;
    int64_t _1649_$retval;
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:20:8:\n    x.>give_num()\n      ^";
    _1649_t1 = _1649_x.vtable->give_num();
    $line_idx--;
    _1649_$retval = _1649_t1;
    return _1649_$retval;
}

int64_t _1645_give_num(void){
    int64_t _1645_$retval;
    _1645_$retval = 302;
    return _1645_$retval;
}


int main(void) {
  printf("%ld",_1647_main());
  return 0;
}
