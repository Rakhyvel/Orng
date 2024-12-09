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
int64_t _1695_main(void);
int64_t _1689_a(void* _1689_$self_ptr, int64_t _1689_x);
int64_t _1691_c(void* _1691_self, int64_t _1691_x);
int64_t _1693_d(int64_t _1693_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1695_main(void){
    int64_t _1695_t1;
    int64_t _1695_t2;
    struct struct3 _1696_my_val;
    struct struct3* _1695_t5;
    int64_t _1695_t6;
    function0 _1695_t7;
    int64_t _1695_t4;
    int64_t _1695_t8;
    int64_t _1695_$retval;
    _1695_t1 = 200;
    _1695_t2 = 45;
    _1696_my_val = (struct struct3) {_1695_t1, _1695_t2};
    _1695_t5 = &_1696_my_val;
    _1695_t6 = 2;
    _1695_t7 = (function0) _1689_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1695_t4 = _1695_t7(_1695_t5, _1695_t6);
    $line_idx--;
    _1695_t8 = 2;
    _1695_$retval = $add_int64_t(_1695_t4, _1695_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1695_$retval;
}

int64_t _1689_a(void* _1689_$self_ptr, int64_t _1689_x){
    struct struct3 _1690_self;
    int64_t _1689_t1;
    int64_t _1689_$retval;
    _1690_self = *(struct struct3*)_1689_$self_ptr;
    _1689_t1 = $mult_int64_t(_1690_self._1, _1689_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1689_$retval = $add_int64_t(_1690_self._0, _1689_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1689_$retval;
}

int64_t _1691_c(void* _1691_self, int64_t _1691_x){
    int64_t _1691_t0;
    int64_t _1691_$retval;
    (*(struct struct3*)_1691_self)._0 = _1691_x;
    _1691_t0 = $mult_int64_t((*(struct struct3*)_1691_self)._1, _1691_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1691_$retval = $add_int64_t((*(struct struct3*)_1691_self)._0, _1691_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1691_$retval;
}

int64_t _1693_d(int64_t _1693_x){
    int64_t _1693_t0;
    int64_t _1693_$retval;
    _1693_t0 = 4;
    _1693_$retval = $add_int64_t(_1693_x, _1693_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1693_$retval;
}


int main(void) {
  printf("%ld",_1695_main());
  return 0;
}
