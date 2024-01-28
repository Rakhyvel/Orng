/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct dyn0;

/* Struct, union, and function definitions */
struct dyn0 {
    void* data_ptr;
    struct vtable_My_Trait* vtable;
};

/* Trait vtable type definitions */
struct vtable_My_Trait {
    int64_t(*get_int)(void*, int64_t);
};

/* Function forward definitions */
int64_t _1594_main(void);
int64_t _1592_get_int(void* _1592_$self_ptr, int64_t _1592_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1590_$vtable = {
    .get_int = _1592_get_int,
};


/* Function definitions */
int64_t _1594_main(void){
    int64_t _1595_x;
    struct dyn0 _1594_t1;
    struct dyn0 _1595_y;
    int64_t _1594_t4;
    int64_t _1594_t3;
    int64_t* _1594_t7;
    int64_t _1594_t8;
    int64_t _1594_t5;
    uint8_t _1594_t10;
    int64_t _1594_$retval;
    _1595_x = 4;
    _1594_t1 = (struct dyn0) {&_1595_x, &_1590_$vtable};
    _1595_y = _1594_t1;
    _1594_t4 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:11:\n    if y.>get_int(90) == x.>get_int(90) {\n         ^";
    _1594_t3 = _1595_y.vtable->get_int(_1595_y.data_ptr, _1594_t4);
    $line_idx--;
    _1594_t7 = &_1595_x;
    _1594_t8 = 90;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:13:29:\n    if y.>get_int(90) == x.>get_int(90) {\n                           ^";
    _1594_t5 = _1590_$vtable.get_int(_1594_t7, _1594_t8);
    $line_idx--;
    _1594_t10 = _1594_t3==_1594_t5;
    if (_1594_t10) {
        goto BB1846;
    } else {
        goto BB1850;
    }
BB1846:
    _1594_$retval = 296;
    return _1594_$retval;
BB1850:
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic-object.orng:16:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1592_get_int(void* _1592_$self_ptr, int64_t _1592_x){
    int64_t _1593_self;
    int64_t _1592_$retval;
    _1593_self = *(int64_t*)_1592_$self_ptr;
    _1592_$retval = $add_int64_t(_1593_self, _1592_x, "tests/integration/traits/receiver-basic-object.orng:7:45:\n    fn get_int(self, x: Int) -> Int { self + x }\n                                           ^");
    return _1592_$retval;
}


int main(void) {
  printf("%ld",_1594_main());
  return 0;
}
