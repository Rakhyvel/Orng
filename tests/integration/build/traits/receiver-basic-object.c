/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct dyn2;

/* Struct, union, and function definitions */
struct struct1 {
    void* _0;
    int64_t _1;
};

typedef int64_t(*function0)(void*, int64_t);

struct dyn2 {
    void* data_ptr;
    struct vtable_My_Trait* vtable;
};

/* Trait vtable type definitions */
struct vtable_My_Trait {
    int64_t(*get_int)(void*, int64_t);
};

/* Function forward definitions */
int64_t _1751_main(void);
int64_t _1749_get_int(void* _1749_$self_ptr, int64_t _1749_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1748_$vtable = {
    .get_int = _1749_get_int,
};


/* Function definitions */
int64_t _1751_main(void){
    int64_t _1752_x;
    struct dyn2 _1751_t2;
    struct dyn2 _1752_y;
    int64_t _1751_t6;
    int64_t _1751_t5;
    int64_t* _1751_t8;
    int64_t _1751_t9;
    int64_t _1751_t7;
    uint8_t _1751_t12;
    int64_t _1751_$retval;
    _1752_x = 4;
    _1751_t2 = (struct dyn2) {&_1752_x, &_1748_$vtable};
    _1752_y = _1751_t2;
    _1751_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1751_t5 = _1752_y.vtable->get_int(_1752_y.data_ptr, _1751_t6);
    $line_idx--;
    _1751_t8 = &_1752_x;
    _1751_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1751_t7 = _1748_$vtable.get_int(_1751_t8, _1751_t9);
    $line_idx--;
    _1751_t12 = _1751_t5==_1751_t7;
    if (_1751_t12) {
        goto BB1923;
    } else {
        goto BB1927;
    }
BB1923:
    _1751_$retval = 296;
    return _1751_$retval;
BB1927:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1749_get_int(void* _1749_$self_ptr, int64_t _1749_x){
    int64_t _1750_self;
    int64_t _1749_$retval;
    _1750_self = *(int64_t*)_1749_$self_ptr;
    _1749_$retval = $add_int64_t(_1750_self, _1749_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1749_$retval;
}


int main(void) {
  printf("%ld",_1751_main());
  return 0;
}
