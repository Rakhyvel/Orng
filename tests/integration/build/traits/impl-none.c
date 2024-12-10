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
int64_t _1710_main(void);
int64_t _1704_a(void* _1704_$self_ptr, int64_t _1704_x);
int64_t _1706_c(void* _1706_self, int64_t _1706_x);
int64_t _1708_d(int64_t _1708_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1710_main(void){
    int64_t _1710_t1;
    int64_t _1710_t2;
    struct struct3 _1711_my_val;
    struct struct3* _1710_t5;
    int64_t _1710_t6;
    function0 _1710_t7;
    int64_t _1710_t4;
    int64_t _1710_t8;
    int64_t _1710_$retval;
    _1710_t1 = 200;
    _1710_t2 = 45;
    _1711_my_val = (struct struct3) {_1710_t1, _1710_t2};
    _1710_t5 = &_1711_my_val;
    _1710_t6 = 2;
    _1710_t7 = (function0) _1704_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1710_t4 = _1710_t7(_1710_t5, _1710_t6);
    $line_idx--;
    _1710_t8 = 2;
    _1710_$retval = $add_int64_t(_1710_t4, _1710_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1710_$retval;
}

int64_t _1704_a(void* _1704_$self_ptr, int64_t _1704_x){
    struct struct3 _1705_self;
    int64_t _1704_t1;
    int64_t _1704_$retval;
    _1705_self = *(struct struct3*)_1704_$self_ptr;
    _1704_t1 = $mult_int64_t(_1705_self._1, _1704_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1704_$retval = $add_int64_t(_1705_self._0, _1704_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1704_$retval;
}

int64_t _1706_c(void* _1706_self, int64_t _1706_x){
    int64_t _1706_t0;
    int64_t _1706_$retval;
    (*(struct struct3*)_1706_self)._0 = _1706_x;
    _1706_t0 = $mult_int64_t((*(struct struct3*)_1706_self)._1, _1706_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1706_$retval = $add_int64_t((*(struct struct3*)_1706_self)._0, _1706_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1706_$retval;
}

int64_t _1708_d(int64_t _1708_x){
    int64_t _1708_t0;
    int64_t _1708_$retval;
    _1708_t0 = 4;
    _1708_$retval = $add_int64_t(_1708_x, _1708_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1708_$retval;
}


int main(void) {
  printf("%ld",_1710_main());
  return 0;
}
