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
int64_t _1630_main(void);
int64_t _1632_call_give_num(struct dyn2 _1632_x);
int64_t _1628_give_num(void);

/* Trait vtable implementations */
struct vtable_Give_Num _1627_$vtable = {
    .give_num = _1628_give_num,
};


/* Function definitions */
int64_t _1630_main(void){
    int64_t _1631_x;
    function1 _1630_t2;
    struct dyn2 _1630_t4;
    int64_t _1630_t3;
    int64_t _1630_$retval;
    _1631_x = 4;
    _1630_t2 = (function1) _1632_call_give_num;
    _1630_t4 = (struct dyn2) {&_1631_x, &_1627_$vtable};
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:15:19:\n    call_give_num(&x)\n                 ^";
    _1630_t3 = _1630_t2(_1630_t4);
    $line_idx--;
    _1630_$retval = _1630_t3;
    return _1630_$retval;
}

int64_t _1632_call_give_num(struct dyn2 _1632_x){
    int64_t _1632_t1;
    int64_t _1632_$retval;
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:20:8:\n    x.>give_num()\n      ^";
    _1632_t1 = _1632_x.vtable->give_num();
    $line_idx--;
    _1632_$retval = _1632_t1;
    return _1632_$retval;
}

int64_t _1628_give_num(void){
    int64_t _1628_$retval;
    _1628_$retval = 302;
    return _1628_$retval;
}


int main(void) {
  printf("%ld",_1630_main());
  return 0;
}
