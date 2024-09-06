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
int64_t _1620_main(void);
int64_t _1622_call_give_num(struct dyn2 _1622_x);
int64_t _1618_give_num(void);

/* Trait vtable implementations */
struct vtable_Give_Num _1617_$vtable = {
    .give_num = _1618_give_num,
};


/* Function definitions */
int64_t _1620_main(void){
    int64_t _1621_x;
    function1 _1620_t2;
    struct dyn2 _1620_t4;
    int64_t _1620_t3;
    int64_t _1620_$retval;
    _1621_x = 4;
    _1620_t2 = (function1) _1622_call_give_num;
    _1620_t4 = (struct dyn2) {&_1621_x, &_1617_$vtable};
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:15:19:\n    call_give_num(&x)\n                 ^";
    _1620_t3 = _1620_t2(_1620_t4);
    $line_idx--;
    _1620_$retval = _1620_t3;
    return _1620_$retval;
}

int64_t _1622_call_give_num(struct dyn2 _1622_x){
    int64_t _1622_t1;
    int64_t _1622_$retval;
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:20:8:\n    x.>give_num()\n      ^";
    _1622_t1 = _1622_x.vtable->give_num();
    $line_idx--;
    _1622_$retval = _1622_t1;
    return _1622_$retval;
}

int64_t _1618_give_num(void){
    int64_t _1618_$retval;
    _1618_$retval = 302;
    return _1618_$retval;
}


int main(void) {
  printf("%ld",_1620_main());
  return 0;
}
