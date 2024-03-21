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
int64_t _1576_main(void);
int64_t _1570_a(void* _1570_$self_ptr, int64_t _1570_x);
int64_t _1572_c(void* _1572_self, int64_t _1572_x);
int64_t _1574_d(int64_t _1574_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1576_main(void){
    int64_t _1576_t1;
    int64_t _1576_t2;
    struct struct3 _1577_my_val;
    struct struct3* _1576_t5;
    int64_t _1576_t6;
    function0 _1576_t7;
    int64_t _1576_t4;
    int64_t _1576_t8;
    int64_t _1576_$retval;
    _1576_t1 = 200;
    _1576_t2 = 45;
    _1577_my_val = (struct struct3) {_1576_t1, _1576_t2};
    _1576_t5 = &_1577_my_val;
    _1576_t6 = 2;
    _1576_t7 = (function0) _1570_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1576_t4 = _1576_t7(_1576_t5, _1576_t6);
    $line_idx--;
    _1576_t8 = 2;
    _1576_$retval = $add_int64_t(_1576_t4, _1576_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1576_$retval;
}

int64_t _1570_a(void* _1570_$self_ptr, int64_t _1570_x){
    struct struct3 _1571_self;
    int64_t _1570_t1;
    int64_t _1570_$retval;
    _1571_self = *(struct struct3*)_1570_$self_ptr;
    _1570_t1 = $mult_int64_t(_1571_self._1, _1570_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1570_$retval = $add_int64_t(_1571_self._0, _1570_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1570_$retval;
}

int64_t _1572_c(void* _1572_self, int64_t _1572_x){
    int64_t _1572_t0;
    int64_t _1572_$retval;
    (*(struct struct3*)_1572_self)._0 = _1572_x;
    _1572_t0 = $mult_int64_t((*(struct struct3*)_1572_self)._1, _1572_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1572_$retval = $add_int64_t((*(struct struct3*)_1572_self)._0, _1572_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1572_$retval;
}

int64_t _1574_d(int64_t _1574_x){
    int64_t _1574_t0;
    int64_t _1574_$retval;
    _1574_t0 = 4;
    _1574_$retval = $add_int64_t(_1574_x, _1574_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1574_$retval;
}


int main(void) {
  printf("%ld",_1576_main());
  return 0;
}
