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
int64_t _1608_main(void);
int64_t _1606_get_int(void* _1606_$self_ptr, int64_t _1606_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1605_$vtable = {
    .get_int = _1606_get_int,
};


/* Function definitions */
int64_t _1608_main(void){
    int64_t _1609_x;
    struct dyn2 _1608_t2;
    struct dyn2 _1609_y;
    int64_t _1608_t6;
    int64_t _1608_t5;
    int64_t* _1608_t8;
    int64_t _1608_t9;
    int64_t _1608_t7;
    uint8_t _1608_t12;
    int64_t _1608_$retval;
    _1609_x = 4;
    _1608_t2 = (struct dyn2) {&_1609_x, &_1605_$vtable};
    _1609_y = _1608_t2;
    _1608_t6 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1608_t5 = _1609_y.vtable->get_int(_1609_y.data_ptr, _1608_t6);
    $line_idx--;
    _1608_t8 = &_1609_x;
    _1608_t9 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1608_t7 = _1605_$vtable.get_int(_1608_t8, _1608_t9);
    $line_idx--;
    _1608_t12 = _1608_t5==_1608_t7;
    if (_1608_t12) {
        goto BB1813;
    } else {
        goto BB1817;
    }
BB1813:
    _1608_$retval = 296;
    return _1608_$retval;
BB1817:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1606_get_int(void* _1606_$self_ptr, int64_t _1606_x){
    int64_t _1607_self;
    int64_t _1606_$retval;
    _1607_self = *(int64_t*)_1606_$self_ptr;
    _1606_$retval = $add_int64_t(_1607_self, _1606_x, "tests/integration/traits/receiver-basic-object.orng:7:53:\n    virtual fn get_int(self, x: Int) -> Int { self + x }\n                                                   ^");
    return _1606_$retval;
}


int main(void) {
  printf("%ld",_1608_main());
  return 0;
}
