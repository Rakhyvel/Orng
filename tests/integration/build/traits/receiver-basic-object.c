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
int64_t _1706_main(void);
int64_t _1704_get_int(void* _1704_$self_ptr, int64_t _1704_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1703_$vtable = {
    .get_int = _1704_get_int,
};


/* Function definitions */
int64_t _1706_main(void){
    int64_t _1707_x;
    struct dyn2 _1706_t2;
    struct dyn2 _1707_y;
    int64_t _1706_t6;
    int64_t _1706_t5;
    int64_t* _1706_t8;
    int64_t _1706_t9;
    int64_t _1706_t7;
    uint8_t _1706_t12;
    int64_t _1706_$retval;
    _1707_x = 4;
    _1706_t2 = (struct dyn2) {&_1707_x, &_1703_$vtable};
    _1707_y = _1706_t2;
    _1706_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1706_t5 = _1707_y.vtable->get_int(_1707_y.data_ptr, _1706_t6);
    $line_idx--;
    _1706_t8 = &_1707_x;
    _1706_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1706_t7 = _1703_$vtable.get_int(_1706_t8, _1706_t9);
    $line_idx--;
    _1706_t12 = _1706_t5==_1706_t7;
    if (_1706_t12) {
        goto BB1908;
    } else {
        goto BB1912;
    }
BB1908:
    _1706_$retval = 296;
    return _1706_$retval;
BB1912:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1704_get_int(void* _1704_$self_ptr, int64_t _1704_x){
    int64_t _1705_self;
    int64_t _1704_$retval;
    _1705_self = *(int64_t*)_1704_$self_ptr;
    _1704_$retval = $add_int64_t(_1705_self, _1704_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1704_$retval;
}


int main(void) {
  printf("%ld",_1706_main());
  return 0;
}
