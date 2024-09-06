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
int64_t _1730_main(void);
int64_t _1728_get_int(void* _1728_$self_ptr, int64_t _1728_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1727_$vtable = {
    .get_int = _1728_get_int,
};


/* Function definitions */
int64_t _1730_main(void){
    int64_t _1731_x;
    struct dyn2 _1730_t2;
    struct dyn2 _1731_y;
    int64_t _1730_t6;
    int64_t _1730_t5;
    int64_t* _1730_t8;
    int64_t _1730_t9;
    int64_t _1730_t7;
    uint8_t _1730_t12;
    int64_t _1730_$retval;
    _1731_x = 4;
    _1730_t2 = (struct dyn2) {&_1731_x, &_1727_$vtable};
    _1731_y = _1730_t2;
    _1730_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1730_t5 = _1731_y.vtable->get_int(_1731_y.data_ptr, _1730_t6);
    $line_idx--;
    _1730_t8 = &_1731_x;
    _1730_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1730_t7 = _1727_$vtable.get_int(_1730_t8, _1730_t9);
    $line_idx--;
    _1730_t12 = _1730_t5==_1730_t7;
    if (_1730_t12) {
        goto BB1912;
    } else {
        goto BB1916;
    }
BB1912:
    _1730_$retval = 296;
    return _1730_$retval;
BB1916:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1728_get_int(void* _1728_$self_ptr, int64_t _1728_x){
    int64_t _1729_self;
    int64_t _1728_$retval;
    _1729_self = *(int64_t*)_1728_$self_ptr;
    _1728_$retval = $add_int64_t(_1729_self, _1728_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1728_$retval;
}


int main(void) {
  printf("%ld",_1730_main());
  return 0;
}
