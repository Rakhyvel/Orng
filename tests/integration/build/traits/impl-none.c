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
int64_t _1591_main(void);
int64_t _1585_a(void* _1585_$self_ptr, int64_t _1585_x);
int64_t _1587_c(void* _1587_self, int64_t _1587_x);
int64_t _1589_d(int64_t _1589_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1591_main(void){
    int64_t _1591_t1;
    int64_t _1591_t2;
    struct struct3 _1592_my_val;
    struct struct3* _1591_t5;
    int64_t _1591_t6;
    function0 _1591_t7;
    int64_t _1591_t4;
    int64_t _1591_t8;
    int64_t _1591_$retval;
    _1591_t1 = 200;
    _1591_t2 = 45;
    _1592_my_val = (struct struct3) {_1591_t1, _1591_t2};
    _1591_t5 = &_1592_my_val;
    _1591_t6 = 2;
    _1591_t7 = (function0) _1585_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1591_t4 = _1591_t7(_1591_t5, _1591_t6);
    $line_idx--;
    _1591_t8 = 2;
    _1591_$retval = $add_int64_t(_1591_t4, _1591_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1591_$retval;
}

int64_t _1585_a(void* _1585_$self_ptr, int64_t _1585_x){
    struct struct3 _1586_self;
    int64_t _1585_t1;
    int64_t _1585_$retval;
    _1586_self = *(struct struct3*)_1585_$self_ptr;
    _1585_t1 = $mult_int64_t(_1586_self._1, _1585_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1585_$retval = $add_int64_t(_1586_self._0, _1585_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1585_$retval;
}

int64_t _1587_c(void* _1587_self, int64_t _1587_x){
    int64_t _1587_t0;
    int64_t _1587_$retval;
    (*(struct struct3*)_1587_self)._0 = _1587_x;
    _1587_t0 = $mult_int64_t((*(struct struct3*)_1587_self)._1, _1587_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1587_$retval = $add_int64_t((*(struct struct3*)_1587_self)._0, _1587_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1587_$retval;
}

int64_t _1589_d(int64_t _1589_x){
    int64_t _1589_t0;
    int64_t _1589_$retval;
    _1589_t0 = 4;
    _1589_$retval = $add_int64_t(_1589_x, _1589_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1589_$retval;
}


int main(void) {
  printf("%ld",_1591_main());
  return 0;
}
