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
int64_t _1655_main(void);
int64_t _1649_a(void* _1649_$self_ptr, int64_t _1649_x);
int64_t _1651_c(void* _1651_self, int64_t _1651_x);
int64_t _1653_d(int64_t _1653_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1655_main(void){
    int64_t _1655_t1;
    int64_t _1655_t2;
    struct struct3 _1656_my_val;
    struct struct3* _1655_t5;
    int64_t _1655_t6;
    function0 _1655_t7;
    int64_t _1655_t4;
    int64_t _1655_t8;
    int64_t _1655_$retval;
    _1655_t1 = 200;
    _1655_t2 = 45;
    _1656_my_val = (struct struct3) {_1655_t1, _1655_t2};
    _1655_t5 = &_1656_my_val;
    _1655_t6 = 2;
    _1655_t7 = (function0) _1649_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1655_t4 = _1655_t7(_1655_t5, _1655_t6);
    $line_idx--;
    _1655_t8 = 2;
    _1655_$retval = $add_int64_t(_1655_t4, _1655_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1655_$retval;
}

int64_t _1649_a(void* _1649_$self_ptr, int64_t _1649_x){
    struct struct3 _1650_self;
    int64_t _1649_t1;
    int64_t _1649_$retval;
    _1650_self = *(struct struct3*)_1649_$self_ptr;
    _1649_t1 = $mult_int64_t(_1650_self._1, _1649_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1649_$retval = $add_int64_t(_1650_self._0, _1649_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1649_$retval;
}

int64_t _1651_c(void* _1651_self, int64_t _1651_x){
    int64_t _1651_t0;
    int64_t _1651_$retval;
    (*(struct struct3*)_1651_self)._0 = _1651_x;
    _1651_t0 = $mult_int64_t((*(struct struct3*)_1651_self)._1, _1651_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1651_$retval = $add_int64_t((*(struct struct3*)_1651_self)._0, _1651_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1651_$retval;
}

int64_t _1653_d(int64_t _1653_x){
    int64_t _1653_t0;
    int64_t _1653_$retval;
    _1653_t0 = 4;
    _1653_$retval = $add_int64_t(_1653_x, _1653_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1653_$retval;
}


int main(void) {
  printf("%ld",_1655_main());
  return 0;
}
