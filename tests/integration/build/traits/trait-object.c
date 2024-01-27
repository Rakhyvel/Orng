/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct dyn0;

/* Struct, union, and function definitions */
struct dyn0 {
    void* data_ptr;
    struct vtable_My_Trait* vtable;
};

/* Trait vtable type definitions */
struct vtable_My_Trait {
    int64_t(*get_int)(void*);
};

/* Function forward definitions */
int64_t _5_main(void);
int64_t _3_get_int(void* _3_$self_ptr);

/* Trait vtable implementations */
struct vtable_My_Trait _2_$vtable = {
    .get_int = _3_get_int,
};


/* Function definitions */
int64_t _5_main(void){
    int64_t _6_x;
    struct dyn0 _5_t1;
    struct dyn0* _5_t4;
    int64_t _5_t3;
    int64_t* _5_t7;
    int64_t _5_t5;
    uint8_t _5_t9;
    int64_t _5_$retval;
    _6_x = 4;
    _5_t1 = (struct dyn0) {&_6_x, &_2_$vtable};
    _5_t4 = &_5_t1;
    $lines[$line_idx++] = "tests/integration/traits/trait-object.orng:13:11:\n    if y.>get_int() == x.>get_int() {\n         ^";
    _5_t3 = _5_t4->vtable->get_int(_5_t4->data_ptr);
    $line_idx--;
    _5_t7 = &_6_x;
    $lines[$line_idx++] = "tests/integration/traits/trait-object.orng:13:27:\n    if y.>get_int() == x.>get_int() {\n                         ^";
    _5_t5 = _2_$vtable.get_int(_5_t7);
    $line_idx--;
    _5_t9 = _5_t3==_5_t5;
    if (_5_t9) {
        goto BB5;
    } else {
        goto BB9;
    }
BB5:
    _5_$retval = 296;
    return _5_$retval;
BB9:
    $lines[$line_idx++] = "tests/integration/traits/trait-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _3_get_int(void* _3_$self_ptr){
    int64_t _3_$retval;
    _3_$retval = *(int64_t*)_3_$self_ptr;
    return _3_$retval;
}


int main(void) {
  printf("%ld",_5_main());
  return 0;
}
