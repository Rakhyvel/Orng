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
int64_t _1740_main(void);
int64_t _1738_get_int(void* _1738_$self_ptr, int64_t _1738_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1737_$vtable = {
    .get_int = _1738_get_int,
};


/* Function definitions */
int64_t _1740_main(void){
    int64_t _1741_x;
    struct dyn2 _1740_t2;
    struct dyn2 _1741_y;
    int64_t _1740_t6;
    int64_t _1740_t5;
    int64_t* _1740_t8;
    int64_t _1740_t9;
    int64_t _1740_t7;
    uint8_t _1740_t12;
    int64_t _1740_$retval;
    _1741_x = 4;
    _1740_t2 = (struct dyn2) {&_1741_x, &_1737_$vtable};
    _1741_y = _1740_t2;
    _1740_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1740_t5 = _1741_y.vtable->get_int(_1741_y.data_ptr, _1740_t6);
    $line_idx--;
    _1740_t8 = &_1741_x;
    _1740_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1740_t7 = _1737_$vtable.get_int(_1740_t8, _1740_t9);
    $line_idx--;
    _1740_t12 = _1740_t5==_1740_t7;
    if (_1740_t12) {
        goto BB1916;
    } else {
        goto BB1920;
    }
BB1916:
    _1740_$retval = 296;
    return _1740_$retval;
BB1920:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1738_get_int(void* _1738_$self_ptr, int64_t _1738_x){
    int64_t _1739_self;
    int64_t _1738_$retval;
    _1739_self = *(int64_t*)_1738_$self_ptr;
    _1738_$retval = $add_int64_t(_1739_self, _1738_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1738_$retval;
}


int main(void) {
  printf("%ld",_1740_main());
  return 0;
}
