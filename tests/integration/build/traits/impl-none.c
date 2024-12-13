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
int64_t _1712_main(void);
int64_t _1706_a(void* _1706_$self_ptr, int64_t _1706_x);
int64_t _1708_c(void* _1708_self, int64_t _1708_x);
int64_t _1710_d(int64_t _1710_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1712_main(void){
    int64_t _1712_t1;
    int64_t _1712_t2;
    struct struct3 _1713_my_val;
    struct struct3* _1712_t5;
    int64_t _1712_t6;
    function0 _1712_t7;
    int64_t _1712_t4;
    int64_t _1712_t8;
    int64_t _1712_$retval;
    _1712_t1 = 200;
    _1712_t2 = 45;
    _1713_my_val = (struct struct3) {_1712_t1, _1712_t2};
    _1712_t5 = &_1713_my_val;
    _1712_t6 = 2;
    _1712_t7 = (function0) _1706_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1712_t4 = _1712_t7(_1712_t5, _1712_t6);
    $line_idx--;
    _1712_t8 = 2;
    _1712_$retval = $add_int64_t(_1712_t4, _1712_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1712_$retval;
}

int64_t _1706_a(void* _1706_$self_ptr, int64_t _1706_x){
    struct struct3 _1707_self;
    int64_t _1706_t1;
    int64_t _1706_$retval;
    _1707_self = *(struct struct3*)_1706_$self_ptr;
    _1706_t1 = $mult_int64_t(_1707_self._1, _1706_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1706_$retval = $add_int64_t(_1707_self._0, _1706_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1706_$retval;
}

int64_t _1708_c(void* _1708_self, int64_t _1708_x){
    int64_t _1708_t0;
    int64_t _1708_$retval;
    (*(struct struct3*)_1708_self)._0 = _1708_x;
    _1708_t0 = $mult_int64_t((*(struct struct3*)_1708_self)._1, _1708_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1708_$retval = $add_int64_t((*(struct struct3*)_1708_self)._0, _1708_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1708_$retval;
}

int64_t _1710_d(int64_t _1710_x){
    int64_t _1710_t0;
    int64_t _1710_$retval;
    _1710_t0 = 4;
    _1710_$retval = $add_int64_t(_1710_x, _1710_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1710_$retval;
}


int main(void) {
  printf("%ld",_1712_main());
  return 0;
}
