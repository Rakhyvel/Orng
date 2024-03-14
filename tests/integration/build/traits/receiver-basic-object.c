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
int64_t _1642_main(void);
int64_t _1640_get_int(void* _1640_$self_ptr, int64_t _1640_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1639_$vtable = {
    .get_int = _1640_get_int,
};


/* Function definitions */
int64_t _1642_main(void){
    int64_t _1643_x;
    struct dyn2 _1642_t2;
    struct dyn2 _1643_y;
    int64_t _1642_t6;
    int64_t _1642_t5;
    int64_t* _1642_t8;
    int64_t _1642_t9;
    int64_t _1642_t7;
    uint8_t _1642_t12;
    int64_t _1642_$retval;
    _1643_x = 4;
    _1642_t2 = (struct dyn2) {&_1643_x, &_1639_$vtable};
    _1643_y = _1642_t2;
    _1642_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1642_t5 = _1643_y.vtable->get_int(_1643_y.data_ptr, _1642_t6);
    $line_idx--;
    _1642_t8 = &_1643_x;
    _1642_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1642_t7 = _1639_$vtable.get_int(_1642_t8, _1642_t9);
    $line_idx--;
    _1642_t12 = _1642_t5==_1642_t7;
    if (_1642_t12) {
        goto BB1866;
    } else {
        goto BB1870;
    }
BB1866:
    _1642_$retval = 296;
    return _1642_$retval;
BB1870:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1640_get_int(void* _1640_$self_ptr, int64_t _1640_x){
    int64_t _1641_self;
    int64_t _1640_$retval;
    _1641_self = *(int64_t*)_1640_$self_ptr;
    _1640_$retval = $add_int64_t(_1641_self, _1640_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1640_$retval;
}


int main(void) {
  printf("%ld",_1642_main());
  return 0;
}
