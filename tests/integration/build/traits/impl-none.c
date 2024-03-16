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
int64_t _51_main(void);
int64_t _45_a(void* _45_$self_ptr, int64_t _45_x);
int64_t _47_c(void* _47_self, int64_t _47_x);
int64_t _49_d(int64_t _49_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _51_main(void){
    int64_t _51_t1;
    int64_t _51_t2;
    struct struct3 _52_my_val;
    struct struct3* _51_t5;
    int64_t _51_t6;
    function0 _51_t7;
    int64_t _51_t4;
    int64_t _51_t8;
    int64_t _51_$retval;
    _51_t1 = 200;
    _51_t2 = 45;
    _52_my_val = (struct struct3) {_51_t1, _51_t2};
    _51_t5 = &_52_my_val;
    _51_t6 = 2;
    _51_t7 = (function0) _45_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _51_t4 = _51_t7(_51_t5, _51_t6);
    $line_idx--;
    _51_t8 = 2;
    _51_$retval = $add_int64_t(_51_t4, _51_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _51_$retval;
}

int64_t _45_a(void* _45_$self_ptr, int64_t _45_x){
    struct struct3 _46_self;
    int64_t _45_t1;
    int64_t _45_$retval;
    _46_self = *(struct struct3*)_45_$self_ptr;
    _45_t1 = $mult_int64_t(_46_self._1, _45_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _45_$retval = $add_int64_t(_46_self._0, _45_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _45_$retval;
}

int64_t _47_c(void* _47_self, int64_t _47_x){
    int64_t _47_t0;
    int64_t _47_$retval;
    (*(struct struct3*)_47_self)._0 = _47_x;
    _47_t0 = $mult_int64_t((*(struct struct3*)_47_self)._1, _47_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _47_$retval = $add_int64_t((*(struct struct3*)_47_self)._0, _47_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _47_$retval;
}

int64_t _49_d(int64_t _49_x){
    int64_t _49_t0;
    int64_t _49_$retval;
    _49_t0 = 4;
    _49_$retval = $add_int64_t(_49_x, _49_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _49_$retval;
}


int main(void) {
  printf("%ld",_51_main());
  return 0;
}
