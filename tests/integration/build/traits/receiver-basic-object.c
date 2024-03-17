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
int64_t _1620_main(void);
int64_t _1618_get_int(void* _1618_$self_ptr, int64_t _1618_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1617_$vtable = {
    .get_int = _1618_get_int,
};


/* Function definitions */
int64_t _1620_main(void){
    int64_t _1621_x;
    struct dyn2 _1620_t2;
    struct dyn2 _1621_y;
    int64_t _1620_t6;
    int64_t _1620_t5;
    int64_t* _1620_t8;
    int64_t _1620_t9;
    int64_t _1620_t7;
    uint8_t _1620_t12;
    int64_t _1620_$retval;
    _1621_x = 4;
    _1620_t2 = (struct dyn2) {&_1621_x, &_1617_$vtable};
    _1621_y = _1620_t2;
    _1620_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1620_t5 = _1621_y.vtable->get_int(_1621_y.data_ptr, _1620_t6);
    $line_idx--;
    _1620_t8 = &_1621_x;
    _1620_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1620_t7 = _1617_$vtable.get_int(_1620_t8, _1620_t9);
    $line_idx--;
    _1620_t12 = _1620_t5==_1620_t7;
    if (_1620_t12) {
        goto BB1819;
    } else {
        goto BB1823;
    }
BB1819:
    _1620_$retval = 296;
    return _1620_$retval;
BB1823:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1618_get_int(void* _1618_$self_ptr, int64_t _1618_x){
    int64_t _1619_self;
    int64_t _1618_$retval;
    _1619_self = *(int64_t*)_1618_$self_ptr;
    _1618_$retval = $add_int64_t(_1619_self, _1618_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1618_$retval;
}


int main(void) {
  printf("%ld",_1620_main());
  return 0;
}
