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
int64_t _1770_main(void);
int64_t _1768_get_int(void* _1768_$self_ptr, int64_t _1768_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1767_$vtable = {
    .get_int = _1768_get_int,
};


/* Function definitions */
int64_t _1770_main(void){
    int64_t _1771_x;
    struct dyn2 _1770_t2;
    struct dyn2 _1771_y;
    int64_t _1770_t6;
    int64_t _1770_t5;
    int64_t* _1770_t8;
    int64_t _1770_t9;
    int64_t _1770_t7;
    uint8_t _1770_t12;
    int64_t _1770_$retval;
    _1771_x = 4;
    _1770_t2 = (struct dyn2) {&_1771_x, &_1767_$vtable};
    _1771_y = _1770_t2;
    _1770_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1770_t5 = _1771_y.vtable->get_int(_1771_y.data_ptr, _1770_t6);
    $line_idx--;
    _1770_t8 = &_1771_x;
    _1770_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1770_t7 = _1767_$vtable.get_int(_1770_t8, _1770_t9);
    $line_idx--;
    _1770_t12 = _1770_t5==_1770_t7;
    if (_1770_t12) {
        goto BB1945;
    } else {
        goto BB1949;
    }
BB1945:
    _1770_$retval = 296;
    return _1770_$retval;
BB1949:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1768_get_int(void* _1768_$self_ptr, int64_t _1768_x){
    int64_t _1769_self;
    int64_t _1768_$retval;
    _1769_self = *(int64_t*)_1768_$self_ptr;
    _1768_$retval = $add_int64_t(_1769_self, _1768_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1768_$retval;
}


int main(void) {
  printf("%ld",_1770_main());
  return 0;
}
