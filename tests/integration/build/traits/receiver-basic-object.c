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
int64_t _1765_main(void);
int64_t _1763_get_int(void* _1763_$self_ptr, int64_t _1763_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1762_$vtable = {
    .get_int = _1763_get_int,
};


/* Function definitions */
int64_t _1765_main(void){
    int64_t _1766_x;
    struct dyn2 _1765_t2;
    struct dyn2 _1766_y;
    int64_t _1765_t6;
    int64_t _1765_t5;
    int64_t* _1765_t8;
    int64_t _1765_t9;
    int64_t _1765_t7;
    uint8_t _1765_t12;
    int64_t _1765_$retval;
    _1766_x = 4;
    _1765_t2 = (struct dyn2) {&_1766_x, &_1762_$vtable};
    _1766_y = _1765_t2;
    _1765_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1765_t5 = _1766_y.vtable->get_int(_1766_y.data_ptr, _1765_t6);
    $line_idx--;
    _1765_t8 = &_1766_x;
    _1765_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1765_t7 = _1762_$vtable.get_int(_1765_t8, _1765_t9);
    $line_idx--;
    _1765_t12 = _1765_t5==_1765_t7;
    if (_1765_t12) {
        goto BB1942;
    } else {
        goto BB1946;
    }
BB1942:
    _1765_$retval = 296;
    return _1765_$retval;
BB1946:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1763_get_int(void* _1763_$self_ptr, int64_t _1763_x){
    int64_t _1764_self;
    int64_t _1763_$retval;
    _1764_self = *(int64_t*)_1763_$self_ptr;
    _1763_$retval = $add_int64_t(_1764_self, _1763_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1763_$retval;
}


int main(void) {
  printf("%ld",_1765_main());
  return 0;
}
