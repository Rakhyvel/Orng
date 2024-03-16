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
int64_t _109_main(void);
int64_t _107_get_int(void* _107_$self_ptr, int64_t _107_x);

/* Trait vtable implementations */
struct vtable_My_Trait _106_$vtable = {
    .get_int = _107_get_int,
};


/* Function definitions */
int64_t _109_main(void){
    int64_t _110_x;
    struct dyn2 _109_t2;
    struct dyn2 _110_y;
    int64_t _109_t6;
    int64_t _109_t5;
    int64_t* _109_t8;
    int64_t _109_t9;
    int64_t _109_t7;
    uint8_t _109_t12;
    int64_t _109_$retval;
    _110_x = 4;
    _109_t2 = (struct dyn2) {&_110_x, &_106_$vtable};
    _110_y = _109_t2;
    _109_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _109_t5 = _110_y.vtable->get_int(_110_y.data_ptr, _109_t6);
    $line_idx--;
    _109_t8 = &_110_x;
    _109_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _109_t7 = _106_$vtable.get_int(_109_t8, _109_t9);
    $line_idx--;
    _109_t12 = _109_t5==_109_t7;
    if (_109_t12) {
        goto BB71;
    } else {
        goto BB75;
    }
BB71:
    _109_$retval = 296;
    return _109_$retval;
BB75:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _107_get_int(void* _107_$self_ptr, int64_t _107_x){
    int64_t _108_self;
    int64_t _107_$retval;
    _108_self = *(int64_t*)_107_$self_ptr;
    _107_$retval = $add_int64_t(_108_self, _107_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _107_$retval;
}


int main(void) {
  printf("%ld",_109_main());
  return 0;
}
