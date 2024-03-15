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
int64_t _1557_main(void);
int64_t _1551_a(void* _1551_$self_ptr, int64_t _1551_x);
int64_t _1553_c(void* _1553_self, int64_t _1553_x);
int64_t _1555_d(int64_t _1555_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1557_main(void){
    int64_t _1557_t1;
    int64_t _1557_t2;
    struct struct3 _1558_my_val;
    struct struct3* _1557_t5;
    int64_t _1557_t6;
    function0 _1557_t7;
    int64_t _1557_t4;
    int64_t _1557_t8;
    int64_t _1557_$retval;
    _1557_t1 = 200;
    _1557_t2 = 45;
    _1558_my_val = (struct struct3) {_1557_t1, _1557_t2};
    _1557_t5 = &_1558_my_val;
    _1557_t6 = 2;
    _1557_t7 = (function0) _1551_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1557_t4 = _1557_t7(_1557_t5, _1557_t6);
    $line_idx--;
    _1557_t8 = 2;
    _1557_$retval = $add_int64_t(_1557_t4, _1557_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1557_$retval;
}

int64_t _1551_a(void* _1551_$self_ptr, int64_t _1551_x){
    struct struct3 _1552_self;
    int64_t _1551_t1;
    int64_t _1551_$retval;
    _1552_self = *(struct struct3*)_1551_$self_ptr;
    _1551_t1 = $mult_int64_t(_1552_self._1, _1551_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1551_$retval = $add_int64_t(_1552_self._0, _1551_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1551_$retval;
}

int64_t _1553_c(void* _1553_self, int64_t _1553_x){
    int64_t _1553_t0;
    int64_t _1553_$retval;
    (*(struct struct3*)_1553_self)._0 = _1553_x;
    _1553_t0 = $mult_int64_t((*(struct struct3*)_1553_self)._1, _1553_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1553_$retval = $add_int64_t((*(struct struct3*)_1553_self)._0, _1553_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1553_$retval;
}

int64_t _1555_d(int64_t _1555_x){
    int64_t _1555_t0;
    int64_t _1555_$retval;
    _1555_t0 = 4;
    _1555_$retval = $add_int64_t(_1555_x, _1555_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1555_$retval;
}


int main(void) {
  printf("%ld",_1557_main());
  return 0;
}
