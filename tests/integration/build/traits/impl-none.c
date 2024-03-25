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
int64_t _1585_main(void);
int64_t _1579_a(void* _1579_$self_ptr, int64_t _1579_x);
int64_t _1581_c(void* _1581_self, int64_t _1581_x);
int64_t _1583_d(int64_t _1583_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1585_main(void){
    int64_t _1585_t1;
    int64_t _1585_t2;
    struct struct3 _1586_my_val;
    struct struct3* _1585_t5;
    int64_t _1585_t6;
    function0 _1585_t7;
    int64_t _1585_t4;
    int64_t _1585_t8;
    int64_t _1585_$retval;
    _1585_t1 = 200;
    _1585_t2 = 45;
    _1586_my_val = (struct struct3) {_1585_t1, _1585_t2};
    _1585_t5 = &_1586_my_val;
    _1585_t6 = 2;
    _1585_t7 = (function0) _1579_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1585_t4 = _1585_t7(_1585_t5, _1585_t6);
    $line_idx--;
    _1585_t8 = 2;
    _1585_$retval = $add_int64_t(_1585_t4, _1585_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1585_$retval;
}

int64_t _1579_a(void* _1579_$self_ptr, int64_t _1579_x){
    struct struct3 _1580_self;
    int64_t _1579_t1;
    int64_t _1579_$retval;
    _1580_self = *(struct struct3*)_1579_$self_ptr;
    _1579_t1 = $mult_int64_t(_1580_self._1, _1579_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1579_$retval = $add_int64_t(_1580_self._0, _1579_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1579_$retval;
}

int64_t _1581_c(void* _1581_self, int64_t _1581_x){
    int64_t _1581_t0;
    int64_t _1581_$retval;
    (*(struct struct3*)_1581_self)._0 = _1581_x;
    _1581_t0 = $mult_int64_t((*(struct struct3*)_1581_self)._1, _1581_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1581_$retval = $add_int64_t((*(struct struct3*)_1581_self)._0, _1581_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1581_$retval;
}

int64_t _1583_d(int64_t _1583_x){
    int64_t _1583_t0;
    int64_t _1583_$retval;
    _1583_t0 = 4;
    _1583_$retval = $add_int64_t(_1583_x, _1583_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1583_$retval;
}


int main(void) {
  printf("%ld",_1585_main());
  return 0;
}
