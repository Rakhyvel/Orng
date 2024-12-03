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
int64_t _147_main(void);
int64_t _145_get_int(void* _145_$self_ptr, int64_t _145_x);

/* Trait vtable implementations */
struct vtable_My_Trait _144_$vtable = {
    .get_int = _145_get_int,
};


/* Function definitions */
int64_t _147_main(void){
    int64_t _148_x;
    struct dyn2 _147_t2;
    struct dyn2 _148_y;
    int64_t _147_t6;
    int64_t _147_t5;
    int64_t* _147_t8;
    int64_t _147_t9;
    int64_t _147_t7;
    uint8_t _147_t12;
    int64_t _147_$retval;
    _148_x = 4;
    _147_t2 = (struct dyn2) {&_148_x, &_144_$vtable};
    _148_y = _147_t2;
    _147_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _147_t5 = _148_y.vtable->get_int(_148_y.data_ptr, _147_t6);
    $line_idx--;
    _147_t8 = &_148_x;
    _147_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _147_t7 = _144_$vtable.get_int(_147_t8, _147_t9);
    $line_idx--;
    _147_t12 = _147_t5==_147_t7;
    if (_147_t12) {
        goto BB85;
    } else {
        goto BB89;
    }
BB85:
    _147_$retval = 296;
    return _147_$retval;
BB89:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _145_get_int(void* _145_$self_ptr, int64_t _145_x){
    int64_t _146_self;
    int64_t _145_$retval;
    _146_self = *(int64_t*)_145_$self_ptr;
    _145_$retval = $add_int64_t(_146_self, _145_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _145_$retval;
}


int main(void) {
  printf("%ld",_147_main());
  return 0;
}
