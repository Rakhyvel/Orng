/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct dyn0;

/* Struct, union, and function definitions */
struct dyn0 {
    void* data_ptr;
    struct vtable_My_Trait* vtable;
};

/* Trait vtable type definitions */
struct vtable_My_Trait {
    int64_t(*get_int)(void*, int64_t);
};

/* Function forward definitions */
int64_t _57_main(void);
int64_t _55_get_int(void* _55_$self_ptr, int64_t _55_x);

/* Trait vtable implementations */
struct vtable_My_Trait _54_$vtable = {
    .get_int = _55_get_int,
};


/* Function definitions */
int64_t _57_main(void){
    int64_t _58_x;
    struct dyn0 _57_t1;
    struct dyn0 _58_y;
    int64_t _57_t4;
    int64_t _57_t3;
    int64_t* _57_t7;
    int64_t _57_t8;
    int64_t _57_t5;
    uint8_t _57_t10;
    int64_t _57_$retval;
    _58_x = 4;
    _57_t1 = (struct dyn0) {&_58_x, &_54_$vtable};
    _58_y = _57_t1;
    _57_t4 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _57_t3 = _58_y.vtable->get_int(_58_y.data_ptr, _57_t4);
    $line_idx--;
    _57_t7 = &_58_x;
    _57_t8 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _57_t5 = _54_$vtable.get_int(_57_t7, _57_t8);
    $line_idx--;
    _57_t10 = _57_t3==_57_t5;
    if (_57_t10) {
        goto BB45;
    } else {
        goto BB49;
    }
BB45:
    _57_$retval = 296;
    return _57_$retval;
BB49:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _55_get_int(void* _55_$self_ptr, int64_t _55_x){
    int64_t _56_self;
    int64_t _55_$retval;
    _56_self = *(int64_t*)_55_$self_ptr;
    _55_$retval = $add_int64_t(_56_self, _55_x, "tests/integration/traits/receiver-basic-object.orng:7:45:\n    fn get_int(self, x: Int) -> Int { self + x }\n                                           ^");
    return _55_$retval;
}


int main(void) {
  printf("%ld",_57_main());
  return 0;
}
