/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct3;

/* Struct, union, and function definitions */
struct struct1 {
    struct struct3* _0;
    int64_t _1;
};

typedef int64_t(*function0)(struct struct3*, int64_t);

typedef int64_t(*function2)(int64_t);

struct struct3 {
    int64_t _0;
    int64_t _1;
};

/* Trait vtable type definitions */
/* Function forward definitions */
int64_t _1640_main(void);
int64_t _1634_a(void* _1634_$self_ptr, int64_t _1634_x);
int64_t _1636_c(void* _1636_self, int64_t _1636_x);
int64_t _1638_d(int64_t _1638_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1640_main(void){
    int64_t _1640_t1;
    int64_t _1640_t2;
    struct struct3 _1641_my_val;
    struct struct3* _1640_t5;
    int64_t _1640_t6;
    function0 _1640_t7;
    int64_t _1640_t4;
    int64_t _1640_t8;
    int64_t _1640_$retval;
    _1640_t1 = 200;
    _1640_t2 = 45;
    _1641_my_val = (struct struct3) {_1640_t1, _1640_t2};
    _1640_t5 = &_1641_my_val;
    _1640_t6 = 2;
    _1640_t7 = (function0) _1634_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1640_t4 = _1640_t7(_1640_t5, _1640_t6);
    $line_idx--;
    _1640_t8 = 2;
    _1640_$retval = $add_int64_t(_1640_t4, _1640_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1640_$retval;
}

int64_t _1634_a(void* _1634_$self_ptr, int64_t _1634_x){
    struct struct3 _1635_self;
    int64_t _1634_t1;
    int64_t _1634_$retval;
    _1635_self = *(struct struct3*)_1634_$self_ptr;
    _1634_t1 = $mult_int64_t(_1635_self._1, _1634_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1634_$retval = $add_int64_t(_1635_self._0, _1634_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1634_$retval;
}

int64_t _1636_c(void* _1636_self, int64_t _1636_x){
    int64_t _1636_t0;
    int64_t _1636_$retval;
    (*(struct struct3*)_1636_self)._0 = _1636_x;
    _1636_t0 = $mult_int64_t((*(struct struct3*)_1636_self)._1, _1636_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1636_$retval = $add_int64_t((*(struct struct3*)_1636_self)._0, _1636_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1636_$retval;
}

int64_t _1638_d(int64_t _1638_x){
    int64_t _1638_t0;
    int64_t _1638_$retval;
    _1638_t0 = 4;
    _1638_$retval = $add_int64_t(_1638_x, _1638_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1638_$retval;
}


int main(void) {
  printf("%ld",_1640_main());
  return 0;
}
