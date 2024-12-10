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
int64_t _1785_main(void);
int64_t _1783_get_int(void* _1783_$self_ptr, int64_t _1783_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1782_$vtable = {
    .get_int = _1783_get_int,
};


/* Function definitions */
int64_t _1785_main(void){
    int64_t _1786_x;
    struct dyn2 _1785_t2;
    struct dyn2 _1786_y;
    int64_t _1785_t6;
    int64_t _1785_t5;
    int64_t* _1785_t8;
    int64_t _1785_t9;
    int64_t _1785_t7;
    uint8_t _1785_t12;
    int64_t _1785_$retval;
    _1786_x = 4;
    _1785_t2 = (struct dyn2) {&_1786_x, &_1782_$vtable};
    _1786_y = _1785_t2;
    _1785_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1785_t5 = _1786_y.vtable->get_int(_1786_y.data_ptr, _1785_t6);
    $line_idx--;
    _1785_t8 = &_1786_x;
    _1785_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1785_t7 = _1782_$vtable.get_int(_1785_t8, _1785_t9);
    $line_idx--;
    _1785_t12 = _1785_t5==_1785_t7;
    if (_1785_t12) {
        goto BB1961;
    } else {
        goto BB1965;
    }
BB1961:
    _1785_$retval = 296;
    return _1785_$retval;
BB1965:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1783_get_int(void* _1783_$self_ptr, int64_t _1783_x){
    int64_t _1784_self;
    int64_t _1783_$retval;
    _1784_self = *(int64_t*)_1783_$self_ptr;
    _1783_$retval = $add_int64_t(_1784_self, _1783_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1783_$retval;
}


int main(void) {
  printf("%ld",_1785_main());
  return 0;
}
