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
int64_t _1562_main(void);
int64_t _1556_a(void* _1556_$self_ptr, int64_t _1556_x);
int64_t _1558_c(void* _1558_self, int64_t _1558_x);
int64_t _1560_d(int64_t _1560_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1562_main(void){
    int64_t _1562_t1;
    int64_t _1562_t2;
    struct struct3 _1563_my_val;
    struct struct3* _1562_t5;
    int64_t _1562_t6;
    function0 _1562_t7;
    int64_t _1562_t4;
    int64_t _1562_t8;
    int64_t _1562_$retval;
    _1562_t1 = 200;
    _1562_t2 = 45;
    _1563_my_val = (struct struct3) {_1562_t1, _1562_t2};
    _1562_t5 = &_1563_my_val;
    _1562_t6 = 2;
    _1562_t7 = (function0) _1556_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1562_t4 = _1562_t7(_1562_t5, _1562_t6);
    $line_idx--;
    _1562_t8 = 2;
    _1562_$retval = $add_int64_t(_1562_t4, _1562_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1562_$retval;
}

int64_t _1556_a(void* _1556_$self_ptr, int64_t _1556_x){
    struct struct3 _1557_self;
    int64_t _1556_t1;
    int64_t _1556_$retval;
    _1557_self = *(struct struct3*)_1556_$self_ptr;
    _1556_t1 = $mult_int64_t(_1557_self._1, _1556_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1556_$retval = $add_int64_t(_1557_self._0, _1556_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1556_$retval;
}

int64_t _1558_c(void* _1558_self, int64_t _1558_x){
    int64_t _1558_t0;
    int64_t _1558_$retval;
    (*(struct struct3*)_1558_self)._0 = _1558_x;
    _1558_t0 = $mult_int64_t((*(struct struct3*)_1558_self)._1, _1558_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1558_$retval = $add_int64_t((*(struct struct3*)_1558_self)._0, _1558_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1558_$retval;
}

int64_t _1560_d(int64_t _1560_x){
    int64_t _1560_t0;
    int64_t _1560_$retval;
    _1560_t0 = 4;
    _1560_$retval = $add_int64_t(_1560_x, _1560_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1560_$retval;
}


int main(void) {
  printf("%ld",_1562_main());
  return 0;
}
