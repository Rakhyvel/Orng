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
int64_t _1577_main(void);
int64_t _1579_call_give_num(struct dyn2 _1579_x);
int64_t _1575_give_num(void);

/* Trait vtable implementations */
struct vtable_Give_Num _1574_$vtable = {
    .give_num = _1575_give_num,
};


/* Function definitions */
int64_t _1577_main(void){
    int64_t _1578_x;
    function1 _1577_t2;
    struct dyn2 _1577_t4;
    int64_t _1577_t3;
    int64_t _1577_$retval;
    _1578_x = 4;
    _1577_t2 = (function1) _1579_call_give_num;
    _1577_t4 = (struct dyn2) {&_1578_x, &_1574_$vtable};
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:15:19:\n    call_give_num(&x)\n                 ^";
    _1577_t3 = _1577_t2(_1577_t4);
    $line_idx--;
    _1577_$retval = _1577_t3;
    return _1577_$retval;
}

int64_t _1579_call_give_num(struct dyn2 _1579_x){
    int64_t _1579_t1;
    int64_t _1579_$retval;
    $lines[$line_idx++] = "tests/integration/traits/dyn-argument.orng:20:8:\n    x.>give_num()\n      ^";
    _1579_t1 = _1579_x.vtable->give_num();
    $line_idx--;
    _1579_$retval = _1579_t1;
    return _1579_$retval;
}

int64_t _1575_give_num(void){
    int64_t _1575_$retval;
    _1575_$retval = 302;
    return _1575_$retval;
}


int main(void) {
  printf("%ld",_1577_main());
  return 0;
}
