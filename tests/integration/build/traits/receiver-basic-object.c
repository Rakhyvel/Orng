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
int64_t _1787_main(void);
int64_t _1785_get_int(void* _1785_$self_ptr, int64_t _1785_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1784_$vtable = {
    .get_int = _1785_get_int,
};


/* Function definitions */
int64_t _1787_main(void){
    int64_t _1788_x;
    struct dyn2 _1787_t2;
    struct dyn2 _1788_y;
    int64_t _1787_t6;
    int64_t _1787_t5;
    int64_t* _1787_t8;
    int64_t _1787_t9;
    int64_t _1787_t7;
    uint8_t _1787_t12;
    int64_t _1787_$retval;
    _1788_x = 4;
    _1787_t2 = (struct dyn2) {&_1788_x, &_1784_$vtable};
    _1788_y = _1787_t2;
    _1787_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1787_t5 = _1788_y.vtable->get_int(_1788_y.data_ptr, _1787_t6);
    $line_idx--;
    _1787_t8 = &_1788_x;
    _1787_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1787_t7 = _1784_$vtable.get_int(_1787_t8, _1787_t9);
    $line_idx--;
    _1787_t12 = _1787_t5==_1787_t7;
    if (_1787_t12) {
        goto BB1963;
    } else {
        goto BB1967;
    }
BB1963:
    _1787_$retval = 296;
    return _1787_$retval;
BB1967:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1785_get_int(void* _1785_$self_ptr, int64_t _1785_x){
    int64_t _1786_self;
    int64_t _1785_$retval;
    _1786_self = *(int64_t*)_1785_$self_ptr;
    _1785_$retval = $add_int64_t(_1786_self, _1785_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1785_$retval;
}


int main(void) {
  printf("%ld",_1787_main());
  return 0;
}
