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
int64_t _1676_main(void);
int64_t _1670_a(void* _1670_$self_ptr, int64_t _1670_x);
int64_t _1672_c(void* _1672_self, int64_t _1672_x);
int64_t _1674_d(int64_t _1674_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1676_main(void){
    int64_t _1676_t1;
    int64_t _1676_t2;
    struct struct3 _1677_my_val;
    struct struct3* _1676_t5;
    int64_t _1676_t6;
    function0 _1676_t7;
    int64_t _1676_t4;
    int64_t _1676_t8;
    int64_t _1676_$retval;
    _1676_t1 = 200;
    _1676_t2 = 45;
    _1677_my_val = (struct struct3) {_1676_t1, _1676_t2};
    _1676_t5 = &_1677_my_val;
    _1676_t6 = 2;
    _1676_t7 = (function0) _1670_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1676_t4 = _1676_t7(_1676_t5, _1676_t6);
    $line_idx--;
    _1676_t8 = 2;
    _1676_$retval = $add_int64_t(_1676_t4, _1676_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1676_$retval;
}

int64_t _1670_a(void* _1670_$self_ptr, int64_t _1670_x){
    struct struct3 _1671_self;
    int64_t _1670_t1;
    int64_t _1670_$retval;
    _1671_self = *(struct struct3*)_1670_$self_ptr;
    _1670_t1 = $mult_int64_t(_1671_self._1, _1670_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1670_$retval = $add_int64_t(_1671_self._0, _1670_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1670_$retval;
}

int64_t _1672_c(void* _1672_self, int64_t _1672_x){
    int64_t _1672_t0;
    int64_t _1672_$retval;
    (*(struct struct3*)_1672_self)._0 = _1672_x;
    _1672_t0 = $mult_int64_t((*(struct struct3*)_1672_self)._1, _1672_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1672_$retval = $add_int64_t((*(struct struct3*)_1672_self)._0, _1672_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1672_$retval;
}

int64_t _1674_d(int64_t _1674_x){
    int64_t _1674_t0;
    int64_t _1674_$retval;
    _1674_t0 = 4;
    _1674_$retval = $add_int64_t(_1674_x, _1674_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1674_$retval;
}


int main(void) {
  printf("%ld",_1676_main());
  return 0;
}
