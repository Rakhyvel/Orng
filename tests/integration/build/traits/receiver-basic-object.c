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
int64_t _1757_main(void);
int64_t _1755_get_int(void* _1755_$self_ptr, int64_t _1755_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1754_$vtable = {
    .get_int = _1755_get_int,
};


/* Function definitions */
int64_t _1757_main(void){
    int64_t _1758_x;
    struct dyn2 _1757_t2;
    struct dyn2 _1758_y;
    int64_t _1757_t6;
    int64_t _1757_t5;
    int64_t* _1757_t8;
    int64_t _1757_t9;
    int64_t _1757_t7;
    uint8_t _1757_t12;
    int64_t _1757_$retval;
    _1758_x = 4;
    _1757_t2 = (struct dyn2) {&_1758_x, &_1754_$vtable};
    _1758_y = _1757_t2;
    _1757_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1757_t5 = _1758_y.vtable->get_int(_1758_y.data_ptr, _1757_t6);
    $line_idx--;
    _1757_t8 = &_1758_x;
    _1757_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1757_t7 = _1754_$vtable.get_int(_1757_t8, _1757_t9);
    $line_idx--;
    _1757_t12 = _1757_t5==_1757_t7;
    if (_1757_t12) {
        goto BB1932;
    } else {
        goto BB1936;
    }
BB1932:
    _1757_$retval = 296;
    return _1757_$retval;
BB1936:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1755_get_int(void* _1755_$self_ptr, int64_t _1755_x){
    int64_t _1756_self;
    int64_t _1755_$retval;
    _1756_self = *(int64_t*)_1755_$self_ptr;
    _1755_$retval = $add_int64_t(_1756_self, _1755_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1755_$retval;
}


int main(void) {
  printf("%ld",_1757_main());
  return 0;
}
