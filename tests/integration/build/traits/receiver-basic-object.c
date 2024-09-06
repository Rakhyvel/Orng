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
int64_t _1737_main(void);
int64_t _1735_get_int(void* _1735_$self_ptr, int64_t _1735_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1734_$vtable = {
    .get_int = _1735_get_int,
};


/* Function definitions */
int64_t _1737_main(void){
    int64_t _1738_x;
    struct dyn2 _1737_t2;
    struct dyn2 _1738_y;
    int64_t _1737_t6;
    int64_t _1737_t5;
    int64_t* _1737_t8;
    int64_t _1737_t9;
    int64_t _1737_t7;
    uint8_t _1737_t12;
    int64_t _1737_$retval;
    _1738_x = 4;
    _1737_t2 = (struct dyn2) {&_1738_x, &_1734_$vtable};
    _1738_y = _1737_t2;
    _1737_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1737_t5 = _1738_y.vtable->get_int(_1738_y.data_ptr, _1737_t6);
    $line_idx--;
    _1737_t8 = &_1738_x;
    _1737_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1737_t7 = _1734_$vtable.get_int(_1737_t8, _1737_t9);
    $line_idx--;
    _1737_t12 = _1737_t5==_1737_t7;
    if (_1737_t12) {
        goto BB1914;
    } else {
        goto BB1918;
    }
BB1914:
    _1737_$retval = 296;
    return _1737_$retval;
BB1918:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1735_get_int(void* _1735_$self_ptr, int64_t _1735_x){
    int64_t _1736_self;
    int64_t _1735_$retval;
    _1736_self = *(int64_t*)_1735_$self_ptr;
    _1735_$retval = $add_int64_t(_1736_self, _1735_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1735_$retval;
}


int main(void) {
  printf("%ld",_1737_main());
  return 0;
}
