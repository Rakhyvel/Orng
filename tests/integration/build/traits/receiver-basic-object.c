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
int64_t _1698_main(void);
int64_t _1696_get_int(void* _1696_$self_ptr, int64_t _1696_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1695_$vtable = {
    .get_int = _1696_get_int,
};


/* Function definitions */
int64_t _1698_main(void){
    int64_t _1699_x;
    struct dyn2 _1698_t2;
    struct dyn2 _1699_y;
    int64_t _1698_t6;
    int64_t _1698_t5;
    int64_t* _1698_t8;
    int64_t _1698_t9;
    int64_t _1698_t7;
    uint8_t _1698_t12;
    int64_t _1698_$retval;
    _1699_x = 4;
    _1698_t2 = (struct dyn2) {&_1699_x, &_1695_$vtable};
    _1699_y = _1698_t2;
    _1698_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1698_t5 = _1699_y.vtable->get_int(_1699_y.data_ptr, _1698_t6);
    $line_idx--;
    _1698_t8 = &_1699_x;
    _1698_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1698_t7 = _1695_$vtable.get_int(_1698_t8, _1698_t9);
    $line_idx--;
    _1698_t12 = _1698_t5==_1698_t7;
    if (_1698_t12) {
        goto BB1897;
    } else {
        goto BB1901;
    }
BB1897:
    _1698_$retval = 296;
    return _1698_$retval;
BB1901:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1696_get_int(void* _1696_$self_ptr, int64_t _1696_x){
    int64_t _1697_self;
    int64_t _1696_$retval;
    _1697_self = *(int64_t*)_1696_$self_ptr;
    _1696_$retval = $add_int64_t(_1697_self, _1696_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1696_$retval;
}


int main(void) {
  printf("%ld",_1698_main());
  return 0;
}
