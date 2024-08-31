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
int64_t _1648_main(void);
int64_t _1646_get_int(void* _1646_$self_ptr, int64_t _1646_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1645_$vtable = {
    .get_int = _1646_get_int,
};


/* Function definitions */
int64_t _1648_main(void){
    int64_t _1649_x;
    struct dyn2 _1648_t2;
    struct dyn2 _1649_y;
    int64_t _1648_t6;
    int64_t _1648_t5;
    int64_t* _1648_t8;
    int64_t _1648_t9;
    int64_t _1648_t7;
    uint8_t _1648_t12;
    int64_t _1648_$retval;
    _1649_x = 4;
    _1648_t2 = (struct dyn2) {&_1649_x, &_1645_$vtable};
    _1649_y = _1648_t2;
    _1648_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1648_t5 = _1649_y.vtable->get_int(_1649_y.data_ptr, _1648_t6);
    $line_idx--;
    _1648_t8 = &_1649_x;
    _1648_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1648_t7 = _1645_$vtable.get_int(_1648_t8, _1648_t9);
    $line_idx--;
    _1648_t12 = _1648_t5==_1648_t7;
    if (_1648_t12) {
        goto BB1839;
    } else {
        goto BB1843;
    }
BB1839:
    _1648_$retval = 296;
    return _1648_$retval;
BB1843:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1646_get_int(void* _1646_$self_ptr, int64_t _1646_x){
    int64_t _1647_self;
    int64_t _1646_$retval;
    _1647_self = *(int64_t*)_1646_$self_ptr;
    _1646_$retval = $add_int64_t(_1647_self, _1646_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1646_$retval;
}


int main(void) {
  printf("%ld",_1648_main());
  return 0;
}
