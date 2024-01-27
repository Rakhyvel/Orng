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
    int64_t(*get_int)(void*, int64_t);
};

/* Function forward definitions */
int64_t _62_main(void);
int64_t _60_get_int(void* _60_$self_ptr, int64_t _60_x);

/* Trait vtable implementations */
struct vtable_My_Trait _59_$vtable = {
    .get_int = _60_get_int,
};


/* Function definitions */
int64_t _62_main(void){
    int64_t _63_x;
    struct dyn0 _62_t1;
    struct dyn0* _62_t4;
    int64_t _62_t5;
    int64_t _62_t3;
    int64_t* _62_t8;
    int64_t _62_t9;
    int64_t _62_t6;
    uint8_t _62_t11;
    int64_t _62_$retval;
    _63_x = 4;
    _62_t1 = (struct dyn0) {&_63_x, &_59_$vtable};
    _62_t4 = &_62_t1;
    _62_t5 = 90;
    $lines[$line_idx++] = "tests/integration/traits/trait-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _62_t3 = _62_t4->vtable->get_int(_62_t4->data_ptr, _62_t5);
    $line_idx--;
    _62_t8 = &_63_x;
    _62_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/trait-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _62_t6 = _59_$vtable.get_int(_62_t8, _62_t9);
    $line_idx--;
    _62_t11 = _62_t3==_62_t6;
    if (_62_t11) {
        goto BB48;
    } else {
        goto BB52;
    }
BB48:
    _62_$retval = 296;
    return _62_$retval;
BB52:
    $lines[$line_idx++] = "tests/integration/traits/trait-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _60_get_int(void* _60_$self_ptr, int64_t _60_x){
    int64_t _61_self;
    int64_t _60_$retval;
    _61_self = *(int64_t*)_60_$self_ptr;
    _60_$retval = $add_int64_t(_61_self, _60_x, "tests/integration/traits/trait-object.orng:7:45:\n    fn get_int(self, x: Int) -> Int { self + x }\n                                           ^");
    return _60_$retval;
}


int main(void) {
  printf("%ld",_62_main());
  return 0;
}
