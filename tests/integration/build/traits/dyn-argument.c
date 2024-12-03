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
int64_t _37_main(void);
int64_t _39_call_give_num(struct dyn2 _39_x);
int64_t _35_give_num(void);

/* Trait vtable implementations */
struct vtable_Give_Num _34_$vtable = {
    .give_num = _35_give_num,
};


/* Function definitions */
int64_t _37_main(void){
    int64_t _38_x;
    function1 _37_t2;
    struct dyn2 _37_t4;
    int64_t _37_t3;
    int64_t _37_$retval;
    _38_x = 4;
    _37_t2 = (function1) _39_call_give_num;
    _37_t4 = (struct dyn2) {&_38_x, &_34_$vtable};
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:15:19:\n    call_give_num(&x)\n                 ^";
    _37_t3 = _37_t2(_37_t4);
    $line_idx--;
    _37_$retval = _37_t3;
    return _37_$retval;
}

int64_t _39_call_give_num(struct dyn2 _39_x){
    int64_t _39_t1;
    int64_t _39_$retval;
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:20:8:\n    x.>give_num()\n      ^";
    _39_t1 = _39_x.vtable->give_num();
    $line_idx--;
    _39_$retval = _39_t1;
    return _39_$retval;
}

int64_t _35_give_num(void){
    int64_t _35_$retval;
    _35_$retval = 302;
    return _35_$retval;
}


int main(void) {
  printf("%ld",_37_main());
  return 0;
}
