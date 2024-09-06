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
int64_t _1665_main(void);
int64_t _1659_a(void* _1659_$self_ptr, int64_t _1659_x);
int64_t _1661_c(void* _1661_self, int64_t _1661_x);
int64_t _1663_d(int64_t _1663_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1665_main(void){
    int64_t _1665_t1;
    int64_t _1665_t2;
    struct struct3 _1666_my_val;
    struct struct3* _1665_t5;
    int64_t _1665_t6;
    function0 _1665_t7;
    int64_t _1665_t4;
    int64_t _1665_t8;
    int64_t _1665_$retval;
    _1665_t1 = 200;
    _1665_t2 = 45;
    _1666_my_val = (struct struct3) {_1665_t1, _1665_t2};
    _1665_t5 = &_1666_my_val;
    _1665_t6 = 2;
    _1665_t7 = (function0) _1659_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1665_t4 = _1665_t7(_1665_t5, _1665_t6);
    $line_idx--;
    _1665_t8 = 2;
    _1665_$retval = $add_int64_t(_1665_t4, _1665_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1665_$retval;
}

int64_t _1659_a(void* _1659_$self_ptr, int64_t _1659_x){
    struct struct3 _1660_self;
    int64_t _1659_t1;
    int64_t _1659_$retval;
    _1660_self = *(struct struct3*)_1659_$self_ptr;
    _1659_t1 = $mult_int64_t(_1660_self._1, _1659_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1659_$retval = $add_int64_t(_1660_self._0, _1659_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1659_$retval;
}

int64_t _1661_c(void* _1661_self, int64_t _1661_x){
    int64_t _1661_t0;
    int64_t _1661_$retval;
    (*(struct struct3*)_1661_self)._0 = _1661_x;
    _1661_t0 = $mult_int64_t((*(struct struct3*)_1661_self)._1, _1661_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1661_$retval = $add_int64_t((*(struct struct3*)_1661_self)._0, _1661_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1661_$retval;
}

int64_t _1663_d(int64_t _1663_x){
    int64_t _1663_t0;
    int64_t _1663_$retval;
    _1663_t0 = 4;
    _1663_$retval = $add_int64_t(_1663_x, _1663_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1663_$retval;
}


int main(void) {
  printf("%ld",_1665_main());
  return 0;
}
