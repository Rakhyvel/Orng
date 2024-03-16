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
int64_t _32_main(void);
int64_t _34_call_give_num(struct dyn2 _34_x);
int64_t _30_give_num(void);

/* Trait vtable implementations */
struct vtable_Give_Num _29_$vtable = {
    .give_num = _30_give_num,
};


/* Function definitions */
int64_t _32_main(void){
    int64_t _33_x;
    function1 _32_t2;
    struct dyn2 _32_t4;
    int64_t _32_t3;
    int64_t _32_$retval;
    _33_x = 4;
    _32_t2 = (function1) _34_call_give_num;
    _32_t4 = (struct dyn2) {&_33_x, &_29_$vtable};
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:15:19:\n    call_give_num(&x)\n                 ^";
    _32_t3 = _32_t2(_32_t4);
    $line_idx--;
    _32_$retval = _32_t3;
    return _32_$retval;
}

int64_t _34_call_give_num(struct dyn2 _34_x){
    int64_t _34_t1;
    int64_t _34_$retval;
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:20:8:\n    x.>give_num()\n      ^";
    _34_t1 = _34_x.vtable->give_num();
    $line_idx--;
    _34_$retval = _34_t1;
    return _34_$retval;
}

int64_t _30_give_num(void){
    int64_t _30_$retval;
    _30_$retval = 302;
    return _30_$retval;
}


int main(void) {
  printf("%ld",_32_main());
  return 0;
}
