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
int64_t _73_main(void);
int64_t _71_get_int(void* _71_$self_ptr, int64_t _71_x);

/* Trait vtable implementations */
struct vtable_My_Trait _70_$vtable = {
    .get_int = _71_get_int,
};


/* Function definitions */
int64_t _73_main(void){
    int64_t _74_x;
    struct dyn2 _73_t1;
    struct dyn2 _74_y;
    int64_t _73_t4;
    int64_t _73_t3;
    int64_t* _73_t6;
    int64_t _73_t7;
    int64_t _73_t5;
    uint8_t _73_t10;
    int64_t _73_$retval;
    _74_x = 4;
    _73_t1 = (struct dyn2) {&_74_x, &_70_$vtable};
    _74_y = _73_t1;
    _73_t4 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _73_t3 = _74_y.vtable->get_int(_74_y.data_ptr, _73_t4);
    $line_idx--;
    _73_t6 = &_74_x;
    _73_t7 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _73_t5 = _70_$vtable.get_int(_73_t6, _73_t7);
    $line_idx--;
    _73_t10 = _73_t3==_73_t5;
    if (_73_t10) {
        goto BB45;
    } else {
        goto BB49;
    }
BB45:
    _73_$retval = 296;
    return _73_$retval;
BB49:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _71_get_int(void* _71_$self_ptr, int64_t _71_x){
    int64_t _72_self;
    int64_t _71_$retval;
    _72_self = *(int64_t*)_71_$self_ptr;
    _71_$retval = $add_int64_t(_72_self, _71_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _71_$retval;
}


int main(void) {
  printf("%ld",_73_main());
  return 0;
}
