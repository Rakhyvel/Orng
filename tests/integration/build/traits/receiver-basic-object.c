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
int64_t _64_main(void);
int64_t _62_get_int(void* _62_$self_ptr, int64_t _62_x);

/* Trait vtable implementations */
struct vtable_My_Trait _61_$vtable = {
    .get_int = _62_get_int,
};


/* Function definitions */
int64_t _64_main(void){
    int64_t _65_x;
    struct dyn2 _64_t1;
    struct dyn2 _65_y;
    int64_t _64_t4;
    int64_t _64_t3;
    int64_t* _64_t6;
    int64_t _64_t7;
    int64_t _64_t5;
    uint8_t _64_t10;
    int64_t _64_$retval;
    _65_x = 4;
    _64_t1 = (struct dyn2) {&_65_x, &_61_$vtable};
    _65_y = _64_t1;
    _64_t4 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _64_t3 = _65_y.vtable->get_int(_65_y.data_ptr, _64_t4);
    $line_idx--;
    _64_t6 = &_65_x;
    _64_t7 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _64_t5 = _61_$vtable.get_int(_64_t6, _64_t7);
    $line_idx--;
    _64_t10 = _64_t3==_64_t5;
    if (_64_t10) {
        goto BB45;
    } else {
        goto BB49;
    }
BB45:
    _64_$retval = 296;
    return _64_$retval;
BB49:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _62_get_int(void* _62_$self_ptr, int64_t _62_x){
    int64_t _63_self;
    int64_t _62_$retval;
    _63_self = *(int64_t*)_62_$self_ptr;
    _62_$retval = $add_int64_t(_63_self, _62_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _62_$retval;
}


int main(void) {
  printf("%ld",_64_main());
  return 0;
}
