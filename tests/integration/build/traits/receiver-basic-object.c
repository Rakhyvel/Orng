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
int64_t _1735_main(void);
int64_t _1733_get_int(void* _1733_$self_ptr, int64_t _1733_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1732_$vtable = {
    .get_int = _1733_get_int,
};


/* Function definitions */
int64_t _1735_main(void){
    int64_t _1736_x;
    struct dyn2 _1735_t2;
    struct dyn2 _1736_y;
    int64_t _1735_t6;
    int64_t _1735_t5;
    int64_t* _1735_t8;
    int64_t _1735_t9;
    int64_t _1735_t7;
    uint8_t _1735_t12;
    int64_t _1735_$retval;
    _1736_x = 4;
    _1735_t2 = (struct dyn2) {&_1736_x, &_1732_$vtable};
    _1736_y = _1735_t2;
    _1735_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1735_t5 = _1736_y.vtable->get_int(_1736_y.data_ptr, _1735_t6);
    $line_idx--;
    _1735_t8 = &_1736_x;
    _1735_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1735_t7 = _1732_$vtable.get_int(_1735_t8, _1735_t9);
    $line_idx--;
    _1735_t12 = _1735_t5==_1735_t7;
    if (_1735_t12) {
        goto BB1912;
    } else {
        goto BB1916;
    }
BB1912:
    _1735_$retval = 296;
    return _1735_$retval;
BB1916:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1733_get_int(void* _1733_$self_ptr, int64_t _1733_x){
    int64_t _1734_self;
    int64_t _1733_$retval;
    _1734_self = *(int64_t*)_1733_$self_ptr;
    _1733_$retval = $add_int64_t(_1734_self, _1733_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1733_$retval;
}


int main(void) {
  printf("%ld",_1735_main());
  return 0;
}
