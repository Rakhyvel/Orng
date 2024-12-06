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
int64_t _1682_main(void);
int64_t _1676_a(void* _1676_$self_ptr, int64_t _1676_x);
int64_t _1678_c(void* _1678_self, int64_t _1678_x);
int64_t _1680_d(int64_t _1680_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1682_main(void){
    int64_t _1682_t1;
    int64_t _1682_t2;
    struct struct3 _1683_my_val;
    struct struct3* _1682_t5;
    int64_t _1682_t6;
    function0 _1682_t7;
    int64_t _1682_t4;
    int64_t _1682_t8;
    int64_t _1682_$retval;
    _1682_t1 = 200;
    _1682_t2 = 45;
    _1683_my_val = (struct struct3) {_1682_t1, _1682_t2};
    _1682_t5 = &_1683_my_val;
    _1682_t6 = 2;
    _1682_t7 = (function0) _1676_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1682_t4 = _1682_t7(_1682_t5, _1682_t6);
    $line_idx--;
    _1682_t8 = 2;
    _1682_$retval = $add_int64_t(_1682_t4, _1682_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1682_$retval;
}

int64_t _1676_a(void* _1676_$self_ptr, int64_t _1676_x){
    struct struct3 _1677_self;
    int64_t _1676_t1;
    int64_t _1676_$retval;
    _1677_self = *(struct struct3*)_1676_$self_ptr;
    _1676_t1 = $mult_int64_t(_1677_self._1, _1676_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1676_$retval = $add_int64_t(_1677_self._0, _1676_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1676_$retval;
}

int64_t _1678_c(void* _1678_self, int64_t _1678_x){
    int64_t _1678_t0;
    int64_t _1678_$retval;
    (*(struct struct3*)_1678_self)._0 = _1678_x;
    _1678_t0 = $mult_int64_t((*(struct struct3*)_1678_self)._1, _1678_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1678_$retval = $add_int64_t((*(struct struct3*)_1678_self)._0, _1678_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1678_$retval;
}

int64_t _1680_d(int64_t _1680_x){
    int64_t _1680_t0;
    int64_t _1680_$retval;
    _1680_t0 = 4;
    _1680_$retval = $add_int64_t(_1680_x, _1680_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1680_$retval;
}


int main(void) {
  printf("%ld",_1682_main());
  return 0;
}
