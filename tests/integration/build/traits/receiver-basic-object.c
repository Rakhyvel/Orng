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
int64_t _1687_main(void);
int64_t _1685_get_int(void* _1685_$self_ptr, int64_t _1685_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1684_$vtable = {
    .get_int = _1685_get_int,
};


/* Function definitions */
int64_t _1687_main(void){
    int64_t _1688_x;
    struct dyn2 _1687_t2;
    struct dyn2 _1688_y;
    int64_t _1687_t6;
    int64_t _1687_t5;
    int64_t* _1687_t8;
    int64_t _1687_t9;
    int64_t _1687_t7;
    uint8_t _1687_t12;
    int64_t _1687_$retval;
    _1688_x = 4;
    _1687_t2 = (struct dyn2) {&_1688_x, &_1684_$vtable};
    _1688_y = _1687_t2;
    _1687_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1687_t5 = _1688_y.vtable->get_int(_1688_y.data_ptr, _1687_t6);
    $line_idx--;
    _1687_t8 = &_1688_x;
    _1687_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1687_t7 = _1684_$vtable.get_int(_1687_t8, _1687_t9);
    $line_idx--;
    _1687_t12 = _1687_t5==_1687_t7;
    if (_1687_t12) {
        goto BB1887;
    } else {
        goto BB1891;
    }
BB1887:
    _1687_$retval = 296;
    return _1687_$retval;
BB1891:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1685_get_int(void* _1685_$self_ptr, int64_t _1685_x){
    int64_t _1686_self;
    int64_t _1685_$retval;
    _1686_self = *(int64_t*)_1685_$self_ptr;
    _1685_$retval = $add_int64_t(_1686_self, _1685_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1685_$retval;
}


int main(void) {
  printf("%ld",_1687_main());
  return 0;
}
