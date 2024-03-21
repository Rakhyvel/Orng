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
int64_t _1634_main(void);
int64_t _1632_get_int(void* _1632_$self_ptr, int64_t _1632_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1631_$vtable = {
    .get_int = _1632_get_int,
};


/* Function definitions */
int64_t _1634_main(void){
    int64_t _1635_x;
    struct dyn2 _1634_t2;
    struct dyn2 _1635_y;
    int64_t _1634_t6;
    int64_t _1634_t5;
    int64_t* _1634_t8;
    int64_t _1634_t9;
    int64_t _1634_t7;
    uint8_t _1634_t12;
    int64_t _1634_$retval;
    _1635_x = 4;
    _1634_t2 = (struct dyn2) {&_1635_x, &_1631_$vtable};
    _1635_y = _1634_t2;
    _1634_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1634_t5 = _1635_y.vtable->get_int(_1635_y.data_ptr, _1634_t6);
    $line_idx--;
    _1634_t8 = &_1635_x;
    _1634_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1634_t7 = _1631_$vtable.get_int(_1634_t8, _1634_t9);
    $line_idx--;
    _1634_t12 = _1634_t5==_1634_t7;
    if (_1634_t12) {
        goto BB1829;
    } else {
        goto BB1833;
    }
BB1829:
    _1634_$retval = 296;
    return _1634_$retval;
BB1833:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1632_get_int(void* _1632_$self_ptr, int64_t _1632_x){
    int64_t _1633_self;
    int64_t _1632_$retval;
    _1633_self = *(int64_t*)_1632_$self_ptr;
    _1632_$retval = $add_int64_t(_1633_self, _1632_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1632_$retval;
}


int main(void) {
  printf("%ld",_1634_main());
  return 0;
}
