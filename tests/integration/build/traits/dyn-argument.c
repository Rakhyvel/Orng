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
int64_t _1615_main(void);
int64_t _1617_call_give_num(struct dyn2 _1617_x);
int64_t _1613_give_num(void);

/* Trait vtable implementations */
struct vtable_Give_Num _1612_$vtable = {
    .give_num = _1613_give_num,
};


/* Function definitions */
int64_t _1615_main(void){
    int64_t _1616_x;
    function1 _1615_t2;
    struct dyn2 _1615_t4;
    int64_t _1615_t3;
    int64_t _1615_$retval;
    _1616_x = 4;
    _1615_t2 = (function1) _1617_call_give_num;
    _1615_t4 = (struct dyn2) {&_1616_x, &_1612_$vtable};
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:15:19:\n    call_give_num(&x)\n                 ^";
    _1615_t3 = _1615_t2(_1615_t4);
    $line_idx--;
    _1615_$retval = _1615_t3;
    return _1615_$retval;
}

int64_t _1617_call_give_num(struct dyn2 _1617_x){
    int64_t _1617_t1;
    int64_t _1617_$retval;
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:20:8:\n    x.>give_num()\n      ^";
    _1617_t1 = _1617_x.vtable->give_num();
    $line_idx--;
    _1617_$retval = _1617_t1;
    return _1617_$retval;
}

int64_t _1613_give_num(void){
    int64_t _1613_$retval;
    _1613_$retval = 302;
    return _1613_$retval;
}


int main(void) {
  printf("%ld",_1615_main());
  return 0;
}
