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
int64_t _1690_main(void);
int64_t _1684_a(void* _1684_$self_ptr, int64_t _1684_x);
int64_t _1686_c(void* _1686_self, int64_t _1686_x);
int64_t _1688_d(int64_t _1688_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1690_main(void){
    int64_t _1690_t1;
    int64_t _1690_t2;
    struct struct3 _1691_my_val;
    struct struct3* _1690_t5;
    int64_t _1690_t6;
    function0 _1690_t7;
    int64_t _1690_t4;
    int64_t _1690_t8;
    int64_t _1690_$retval;
    _1690_t1 = 200;
    _1690_t2 = 45;
    _1691_my_val = (struct struct3) {_1690_t1, _1690_t2};
    _1690_t5 = &_1691_my_val;
    _1690_t6 = 2;
    _1690_t7 = (function0) _1684_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1690_t4 = _1690_t7(_1690_t5, _1690_t6);
    $line_idx--;
    _1690_t8 = 2;
    _1690_$retval = $add_int64_t(_1690_t4, _1690_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1690_$retval;
}

int64_t _1684_a(void* _1684_$self_ptr, int64_t _1684_x){
    struct struct3 _1685_self;
    int64_t _1684_t1;
    int64_t _1684_$retval;
    _1685_self = *(struct struct3*)_1684_$self_ptr;
    _1684_t1 = $mult_int64_t(_1685_self._1, _1684_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1684_$retval = $add_int64_t(_1685_self._0, _1684_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1684_$retval;
}

int64_t _1686_c(void* _1686_self, int64_t _1686_x){
    int64_t _1686_t0;
    int64_t _1686_$retval;
    (*(struct struct3*)_1686_self)._0 = _1686_x;
    _1686_t0 = $mult_int64_t((*(struct struct3*)_1686_self)._1, _1686_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1686_$retval = $add_int64_t((*(struct struct3*)_1686_self)._0, _1686_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1686_$retval;
}

int64_t _1688_d(int64_t _1688_x){
    int64_t _1688_t0;
    int64_t _1688_$retval;
    _1688_t0 = 4;
    _1688_$retval = $add_int64_t(_1688_x, _1688_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1688_$retval;
}


int main(void) {
  printf("%ld",_1690_main());
  return 0;
}
