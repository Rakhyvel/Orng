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
int64_t _1625_main(void);
int64_t _1627_call_give_num(struct dyn2 _1627_x);
int64_t _1623_give_num(void);

/* Trait vtable implementations */
struct vtable_Give_Num _1622_$vtable = {
    .give_num = _1623_give_num,
};


/* Function definitions */
int64_t _1625_main(void){
    int64_t _1626_x;
    function1 _1625_t2;
    struct dyn2 _1625_t4;
    int64_t _1625_t3;
    int64_t _1625_$retval;
    _1626_x = 4;
    _1625_t2 = (function1) _1627_call_give_num;
    _1625_t4 = (struct dyn2) {&_1626_x, &_1622_$vtable};
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:15:19:\n    call_give_num(&x)\n                 ^";
    _1625_t3 = _1625_t2(_1625_t4);
    $line_idx--;
    _1625_$retval = _1625_t3;
    return _1625_$retval;
}

int64_t _1627_call_give_num(struct dyn2 _1627_x){
    int64_t _1627_t1;
    int64_t _1627_$retval;
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:20:8:\n    x.>give_num()\n      ^";
    _1627_t1 = _1627_x.vtable->give_num();
    $line_idx--;
    _1627_$retval = _1627_t1;
    return _1627_$retval;
}

int64_t _1623_give_num(void){
    int64_t _1623_$retval;
    _1623_$retval = 302;
    return _1623_$retval;
}


int main(void) {
  printf("%ld",_1625_main());
  return 0;
}
