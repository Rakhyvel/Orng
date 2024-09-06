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
int64_t _1648_main(void);
int64_t _1642_a(void* _1642_$self_ptr, int64_t _1642_x);
int64_t _1644_c(void* _1644_self, int64_t _1644_x);
int64_t _1646_d(int64_t _1646_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1648_main(void){
    int64_t _1648_t1;
    int64_t _1648_t2;
    struct struct3 _1649_my_val;
    struct struct3* _1648_t5;
    int64_t _1648_t6;
    function0 _1648_t7;
    int64_t _1648_t4;
    int64_t _1648_t8;
    int64_t _1648_$retval;
    _1648_t1 = 200;
    _1648_t2 = 45;
    _1649_my_val = (struct struct3) {_1648_t1, _1648_t2};
    _1648_t5 = &_1649_my_val;
    _1648_t6 = 2;
    _1648_t7 = (function0) _1642_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1648_t4 = _1648_t7(_1648_t5, _1648_t6);
    $line_idx--;
    _1648_t8 = 2;
    _1648_$retval = $add_int64_t(_1648_t4, _1648_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1648_$retval;
}

int64_t _1642_a(void* _1642_$self_ptr, int64_t _1642_x){
    struct struct3 _1643_self;
    int64_t _1642_t1;
    int64_t _1642_$retval;
    _1643_self = *(struct struct3*)_1642_$self_ptr;
    _1642_t1 = $mult_int64_t(_1643_self._1, _1642_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1642_$retval = $add_int64_t(_1643_self._0, _1642_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1642_$retval;
}

int64_t _1644_c(void* _1644_self, int64_t _1644_x){
    int64_t _1644_t0;
    int64_t _1644_$retval;
    (*(struct struct3*)_1644_self)._0 = _1644_x;
    _1644_t0 = $mult_int64_t((*(struct struct3*)_1644_self)._1, _1644_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1644_$retval = $add_int64_t((*(struct struct3*)_1644_self)._0, _1644_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1644_$retval;
}

int64_t _1646_d(int64_t _1646_x){
    int64_t _1646_t0;
    int64_t _1646_$retval;
    _1646_t0 = 4;
    _1646_$retval = $add_int64_t(_1646_x, _1646_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1646_$retval;
}


int main(void) {
  printf("%ld",_1648_main());
  return 0;
}
