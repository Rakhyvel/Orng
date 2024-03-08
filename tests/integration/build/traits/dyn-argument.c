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
int64_t _6_main(void);
int64_t _8_call_give_num(struct dyn2 _8_x);
int64_t _4_give_num(void);

/* Trait vtable implementations */
struct vtable_Give_Num _3_$vtable = {
    .give_num = _4_give_num,
};


/* Function definitions */
int64_t _6_main(void){
    int64_t _7_x;
    function1 _6_t1;
    struct dyn2 _6_t3;
    int64_t _6_t2;
    int64_t _6_$retval;
    _7_x = 4;
    _6_t1 = (function1) _8_call_give_num;
    _6_t3 = (struct dyn2) {&_7_x, &_3_$vtable};
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:15:19:\n    call_give_num(&x)\n                 ^";
    _6_t2 = _6_t1(_6_t3);
    $line_idx--;
    _6_$retval = _6_t2;
    return _6_$retval;
}

int64_t _8_call_give_num(struct dyn2 _8_x){
    int64_t _8_t1;
    int64_t _8_$retval;
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:20:8:\n    x.>give_num()\n      ^";
    _8_t1 = _8_x.vtable->give_num();
    $line_idx--;
    _8_$retval = _8_t1;
    return _8_$retval;
}

int64_t _4_give_num(void){
    int64_t _4_$retval;
    _4_$retval = 302;
    return _4_$retval;
}


int main(void) {
  printf("%ld",_6_main());
  return 0;
}
