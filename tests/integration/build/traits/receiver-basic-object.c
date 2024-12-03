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
int64_t _1745_main(void);
int64_t _1743_get_int(void* _1743_$self_ptr, int64_t _1743_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1742_$vtable = {
    .get_int = _1743_get_int,
};


/* Function definitions */
int64_t _1745_main(void){
    int64_t _1746_x;
    struct dyn2 _1745_t2;
    struct dyn2 _1746_y;
    int64_t _1745_t6;
    int64_t _1745_t5;
    int64_t* _1745_t8;
    int64_t _1745_t9;
    int64_t _1745_t7;
    uint8_t _1745_t12;
    int64_t _1745_$retval;
    _1746_x = 4;
    _1745_t2 = (struct dyn2) {&_1746_x, &_1742_$vtable};
    _1746_y = _1745_t2;
    _1745_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1745_t5 = _1746_y.vtable->get_int(_1746_y.data_ptr, _1745_t6);
    $line_idx--;
    _1745_t8 = &_1746_x;
    _1745_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1745_t7 = _1742_$vtable.get_int(_1745_t8, _1745_t9);
    $line_idx--;
    _1745_t12 = _1745_t5==_1745_t7;
    if (_1745_t12) {
        goto BB1920;
    } else {
        goto BB1924;
    }
BB1920:
    _1745_$retval = 296;
    return _1745_$retval;
BB1924:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1743_get_int(void* _1743_$self_ptr, int64_t _1743_x){
    int64_t _1744_self;
    int64_t _1743_$retval;
    _1744_self = *(int64_t*)_1743_$self_ptr;
    _1743_$retval = $add_int64_t(_1744_self, _1743_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1743_$retval;
}


int main(void) {
  printf("%ld",_1745_main());
  return 0;
}
