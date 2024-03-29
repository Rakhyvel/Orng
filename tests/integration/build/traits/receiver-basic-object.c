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
int64_t _1643_main(void);
int64_t _1641_get_int(void* _1641_$self_ptr, int64_t _1641_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1640_$vtable = {
    .get_int = _1641_get_int,
};


/* Function definitions */
int64_t _1643_main(void){
    int64_t _1644_x;
    struct dyn2 _1643_t2;
    struct dyn2 _1644_y;
    int64_t _1643_t6;
    int64_t _1643_t5;
    int64_t* _1643_t8;
    int64_t _1643_t9;
    int64_t _1643_t7;
    uint8_t _1643_t12;
    int64_t _1643_$retval;
    _1644_x = 4;
    _1643_t2 = (struct dyn2) {&_1644_x, &_1640_$vtable};
    _1644_y = _1643_t2;
    _1643_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1643_t5 = _1644_y.vtable->get_int(_1644_y.data_ptr, _1643_t6);
    $line_idx--;
    _1643_t8 = &_1644_x;
    _1643_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1643_t7 = _1640_$vtable.get_int(_1643_t8, _1643_t9);
    $line_idx--;
    _1643_t12 = _1643_t5==_1643_t7;
    if (_1643_t12) {
        goto BB1835;
    } else {
        goto BB1839;
    }
BB1835:
    _1643_$retval = 296;
    return _1643_$retval;
BB1839:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1641_get_int(void* _1641_$self_ptr, int64_t _1641_x){
    int64_t _1642_self;
    int64_t _1641_$retval;
    _1642_self = *(int64_t*)_1641_$self_ptr;
    _1641_$retval = $add_int64_t(_1642_self, _1641_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1641_$retval;
}


int main(void) {
  printf("%ld",_1643_main());
  return 0;
}
