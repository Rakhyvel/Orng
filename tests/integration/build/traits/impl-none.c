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
int64_t _46_main(void);
int64_t _40_a(void* _40_$self_ptr, int64_t _40_x);
int64_t _42_c(void* _42_self, int64_t _42_x);
int64_t _44_d(int64_t _44_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _46_main(void){
    int64_t _46_t1;
    int64_t _46_t2;
    struct struct3 _47_my_val;
    struct struct3* _46_t4;
    int64_t _46_t5;
    function0 _46_t6;
    int64_t _46_t3;
    int64_t _46_t7;
    int64_t _46_$retval;
    _46_t1 = 200;
    _46_t2 = 45;
    _47_my_val = (struct struct3) {_46_t1, _46_t2};
    _46_t4 = &_47_my_val;
    _46_t5 = 2;
    _46_t6 = (function0) _40_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _46_t3 = _46_t6(_46_t4, _46_t5);
    $line_idx--;
    _46_t7 = 2;
    _46_$retval = $add_int64_t(_46_t3, _46_t7, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _46_$retval;
}

int64_t _40_a(void* _40_$self_ptr, int64_t _40_x){
    struct struct3 _41_self;
    int64_t _40_t0;
    int64_t _40_$retval;
    _41_self = *(struct struct3*)_40_$self_ptr;
    _40_t0 = $mult_int64_t(_41_self._1, _40_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _40_$retval = $add_int64_t(_41_self._0, _40_t0, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _40_$retval;
}

int64_t _42_c(void* _42_self, int64_t _42_x){
    int64_t _42_t0;
    int64_t _42_$retval;
    (*(struct struct3*)_42_self)._0 = _42_x;
    _42_t0 = $mult_int64_t((*(struct struct3*)_42_self)._1, _42_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _42_$retval = $add_int64_t((*(struct struct3*)_42_self)._0, _42_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _42_$retval;
}

int64_t _44_d(int64_t _44_x){
    int64_t _44_t0;
    int64_t _44_$retval;
    _44_t0 = 4;
    _44_$retval = $add_int64_t(_44_x, _44_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _44_$retval;
}


int main(void) {
  printf("%ld",_46_main());
  return 0;
}
