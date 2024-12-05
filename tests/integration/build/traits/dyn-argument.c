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
int64_t _1641_main(void);
int64_t _1643_call_give_num(struct dyn2 _1643_x);
int64_t _1639_give_num(void);

/* Trait vtable implementations */
struct vtable_Give_Num _1638_$vtable = {
    .give_num = _1639_give_num,
};


/* Function definitions */
int64_t _1641_main(void){
    int64_t _1642_x;
    function1 _1641_t2;
    struct dyn2 _1641_t4;
    int64_t _1641_t3;
    int64_t _1641_$retval;
    _1642_x = 4;
    _1641_t2 = (function1) _1643_call_give_num;
    _1641_t4 = (struct dyn2) {&_1642_x, &_1638_$vtable};
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:15:19:\n    call_give_num(&x)\n                 ^";
    _1641_t3 = _1641_t2(_1641_t4);
    $line_idx--;
    _1641_$retval = _1641_t3;
    return _1641_$retval;
}

int64_t _1643_call_give_num(struct dyn2 _1643_x){
    int64_t _1643_t1;
    int64_t _1643_$retval;
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:20:8:\n    x.>give_num()\n      ^";
    _1643_t1 = _1643_x.vtable->give_num();
    $line_idx--;
    _1643_$retval = _1643_t1;
    return _1643_$retval;
}

int64_t _1639_give_num(void){
    int64_t _1639_$retval;
    _1639_$retval = 302;
    return _1639_$retval;
}


int main(void) {
  printf("%ld",_1641_main());
  return 0;
}
